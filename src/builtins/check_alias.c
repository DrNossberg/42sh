/*
** EPITECH PROJECT, 2017
** PSU_42sh_2017
** File description:
** Created by davy.henry,
*/

#include <memory.h>
#include "my_exit.h"

static char *change_alias(char *save, alias_s *tmp, size_t a)
{
	char *alias = strdup(tmp->alias);

	if (strlen(save) > a) {
		for (size_t i = 0; i < a; i++, save++);
		return (strcat(alias, save));
	}
	return (alias);
}

char *check_alias(nb_exit_t *buffer, char *save)
{
	alias_s *tmp = buffer->alias;
	size_t a;

	for (int i = 0; i < buffer->n_of_alias; i++) {
		a = strlen(tmp->name);
		if (!strncmp(save, tmp->name, a))
			return (change_alias(save, tmp, a));
		tmp = tmp->next;
	}
	return (save);
}
