/*
** Cnam, en partenariat avec l'ITII Alsace, 2023
** Projet :
**    42sh
** Author :
**    Julien  DUBOCAGE
**    Antoine ORION
** File description:
** .c
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "get_next_line.h"
#include "../../include/my.h"

int check_n(char *buffer, int k)
{
	int i = 0;

	if (k != 0) {
		while (buffer[i] != '\0')
			i++;
		return (i);
	}
	while (buffer[i] != '\0') {
		if (buffer[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}

static char *my_pseudo_strncat(char *d, char *s, int nb)
{
	int i = 0;
	int j = 0;
	int size_dest = check_n(d, 1);
	char *save = malloc(sizeof(char) * (check_n(d, 1) + check_n(s, 1) + 1));

	if (save == NULL)
		return (NULL);
	save[check_n(d, 1) + check_n(s, 1)] = '\0';
	while (j != size_dest) {
		save[j] = d[j];
		j++;
	}
	save[j] = '\0';
	while (s[i] != '\0' && i < nb) {
		save[size_dest + i] = s[i];
		i++;
	}
	save[size_dest + i] = '\0';
	return (save);
}

static char *check_buffer(int fd, char *buffer)
{
	char *save_buffer =  malloc(sizeof(char) * (READ_SIZE + 1));
	int i = check_n(buffer, 0);
	int save_read = 0;

	if (save_buffer == NULL)
		return (NULL);
	save_buffer[READ_SIZE] = '\0';
	while (i != 0) {
		save_read = read(fd, save_buffer, READ_SIZE);
		if (save_read == 0 && check_n(buffer, 1))
			return (buffer);
		if (save_read == 0)
			return (NULL);
		if (save_read == -1)
			return (NULL);
		save_buffer[save_read] = '\0';
		buffer = my_pseudo_strncat(buffer, save_buffer, READ_SIZE);
		i = check_n(save_buffer, 0);
	}
	return (buffer);
}

static char *init_buffer(char *buffer, int fd)
{
	int save_read = 0;

	if (fd < 0 || READ_SIZE <= 0)
		return (NULL);
	if (buffer == NULL) {
		buffer = malloc(sizeof(char) * (READ_SIZE + 1));
		if (buffer == NULL)
			return (NULL);
		save_read = read(fd, buffer, READ_SIZE);
		if (save_read <= 0)
			return (NULL);
		buffer[save_read] = '\0';
	}
	buffer = check_buffer(fd, buffer);
	if (buffer == NULL)
		return (NULL);
	return (buffer);
}

char *get_next_line(int fd)
{
	static char *buffer;
	char *print_buffer = NULL;
	int j = 0;

	buffer = init_buffer(buffer, fd);
	if (buffer == NULL)
		return (NULL);
	for (; buffer[j] != '\n' && buffer[j] != '\0'; j++);
	print_buffer = strndup(buffer, j);
	if (print_buffer == NULL)
		return (NULL);
	print_buffer[j] = '\0';
	buffer = buffer + j + 1;
	return (print_buffer);
}
