/*
** EPITECH PROJECT, 2018
** parse
** File description:
** .c
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "../include/my.h"
#include "../include/my_exit.h"

char *new_cmd(char *instru, int i)
{
	char *save = malloc(sizeof(char) * (i + 1));
	int k = 0;

	if (!save)
		return (NULL);
	for (k = 0; k < i; k++)
		save[k] = instru[k];
	save[k] = '\0';
	return (save);
}

char *recup_name_file(char *instru)
{
	char *tmp = my_strdup(instru);

	for (; *tmp && (*tmp == ' ' || *tmp == '\t'); tmp++);
	return (tmp);
}

int my_choice_redirection(char *instru, int i, nb_exit_t **buffer, int *k)
{
	if (instru[i + 1] == '\0')
		return (-1);
	if (instru[i] == '>')
		return (output_redi(instru, i));
	return (input_redi(instru, i, buffer, k));
}

char *my_exit_for_redi(char *instru, int i, nb_exit_t **buffer, int *k)
{
	char *tmp = new_cmd(instru, i);

	my_choice_redirection(instru, i, buffer, k);
	return (tmp);
}

char *my_parse_instru(char *instru, nb_exit_t **buffer, int *k)
{
	for (int i = 0; instru[i];) {
		if (instru[i] == '>' || instru[i] == '<')
			return (my_exit_for_redi(instru, i, buffer, k));
		if (instru[i])
			i++;
	}
	return (instru);
}
