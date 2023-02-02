/*
** Cnam, en partenariat avec l'ITII Alsace, 2023
** Projet :
**    42sh
** Author :
**    Julien  DUBOCAGE
**    Antoine ORION
** File description:
** Created by davy.henry,
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "my_exit.h"

static int is_space(char const *str)
{
	for (int i = 0; str[i]; i++)
		if (str[i] == ' ' || str[i] == '\t')
			return (1);
	return (0);
}

static void print_alias(nb_exit_t *buffer)
{
	alias_s *tmp = buffer->alias;

	if (buffer->n_of_alias == 0)
		return;
	for (int i = 0; i < buffer->n_of_alias; i++) {
		printf("%s\t", tmp->name);
		if (!is_space(tmp->alias))
			printf("%s\n", tmp->alias);
		else
			printf("(%s)\n", tmp->alias);
		tmp = tmp->next;
	}
}

static void find_alias(nb_exit_t *buffer, char *name)
{
	alias_s *tmp = buffer->alias;

	for (int i = 0; i < buffer->n_of_alias; i++) {
		if (!strcmp(name, tmp->name)) {
			printf("%s\n", tmp->alias);
			return;
		}
		tmp = tmp->next;
	}
}

static void add_alias(nb_exit_t *buffer, char **tab, int a)
{
	alias_s *tmp = buffer->alias;
	char *cmd = NULL;

	if (buffer->alias == NULL) {
		tmp = malloc(sizeof(alias_s *));
		buffer->alias = tmp;
	} else {
		for (int i = 1; i < buffer->n_of_alias; i++)
			tmp = tmp->next;
		tmp->next = malloc(sizeof(alias_s *));
		tmp = tmp->next;
	}
	tmp->name = strdup(tab[1]);
	cmd = strdup(tab[2]);
	for (int i = 3; i < a; i++) {
		cmd = strcat(cmd, " ");
		cmd = strcat(cmd, tab[i]);
	}
	tmp->alias = cmd;
	buffer->n_of_alias++;
}

char **my_alias(char **env, char **tab, nb_exit_t **buffer)
{
	int a = number_arg(tab);

	if (a == 1) {
		if (buffer[0]->n_of_alias == 0)
			return (env);
		print_alias(*buffer);
	}
	if (a == 2)
		find_alias(*buffer, tab[1]);
	if (a >= 3)
		add_alias(*buffer, tab, a);
	return (env);
}
