/**
* @file parser_for_redi.c
* @author Antoine Orion
* @author Julien Dubocage
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "../include/my.h"
#include "../include/my_exit.h"

int output_redi(char *instru, int i)
{
	int fd = 0;

	if (instru[i + 1] == '>')
		fd = open(recup_name_file(instru + i + 2),
			O_CREAT | O_RDWR | O_APPEND, 0640);
	else
		fd = open(recup_name_file(instru + i + 1),
			O_CREAT | O_RDWR | O_TRUNC, 0640);
	if (fd == -1)
		return (-1);
	dup2(fd, 1);
	close(fd);
	return (0);
}

void write_instru_for_redi(char *buf, int *fd)
{
	write(fd[1], buf, strlen(buf));
	write(fd[1], "\n", 1);
}

int recover_input(char *buf, int fd[2], char *name)
{
	write(1, "> ", 2);
	buf = get_next_line(0);
	if (!buf)
		return (0);
	if (strncmp(name, buf, strlen(buf)))
		write_instru_for_redi(buf, fd);
	for (; buf && strncmp(name, buf, strlen(name));) {
		write(1, "> ", 2);
		free(buf);
		buf = get_next_line(0);
		if (!buf)
			break;
		if (strncmp(name, buf, strlen(buf)))
			write_instru_for_redi(buf, fd);
	}
	close(fd[1]);
	dup2(fd[0], 0);
	close(fd[0]);
	free(buf);
	return (0);
}

int input_redi_two(char *instru, int i, nb_exit_t **buffer, int *k)
{
	int fd[2];
	char *name = epurstring(recup_name_file(instru + i + 2));

	buffer = buffer;
	k = k;
	if (pipe(fd) == -1)
		return (-1);
	recover_input(NULL, fd, name);
	return (0);
}

int input_redi(char *instru, int i, nb_exit_t **buffer, int *k)
{
	int fd = 0;
	char *tmp = recup_name_file(instru + i + 1);

	if (instru[i + 1] == '<') {
		input_redi_two(instru, i, buffer, k);
		return (0);
	} else
		fd = open(tmp, O_RDONLY);
	if (fd == -1) {
		my_error(tmp);
		my_error(": No such file or directory.\n");
		buffer[0]->nb_exit = 1;
		k[0] = 1;
	}
	dup2(fd, 0);
	close(fd);
	return (0);
}
