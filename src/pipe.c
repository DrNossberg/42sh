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

#include "../include/my.h"
#include "../include/my_exit.h"

int display_error_pipe(char **pipe, nb_exit_t **buffer)
{
	pipe = pipe;
	my_error("Invalid null command.\n");
	buffer[0]->nb_exit = 1;
	return (0);
}

int check_pipe_error(char **pipe, nb_exit_t **buffer)
{
	int i = 0;

	for (; pipe[i]; i++) {
		if (!strlen(pipe[i]))
			return (display_error_pipe(pipe, buffer));
	}
	return (0);
}

int *pipe_with_wait(int nb_of_pipe)
{
	int *nb_multi_wait = malloc(sizeof(int) * (nb_of_pipe + 1));

	if (!nb_multi_wait)
		return (NULL);
	nb_multi_wait[nb_of_pipe] = -1;
	for (int i = 0; i < nb_of_pipe; i++)
		nb_multi_wait[i] = -1;
	return (nb_multi_wait);
}

int count_pipe(char **pipe)
{
	int i = 0;

	for (; pipe[i]; i++);
	return (i - 1);
}

int multi_pipe(int input, int i, char **save_instru)
{
	static int pipe_array[2];

	if (i)
		input = pipe_array[0];
	if (pipe(pipe_array) == -1)
		return (-1);
	if (save_instru[i + 1]) {
		dup2(pipe_array[1], 1);
		close(pipe_array[1]);
	}
	dup2(input, 0);
	return (0);
}
