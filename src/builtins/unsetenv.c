/*
** EPITECH PROJECT, 2018
** setenv
** File description:
** .c
*/

#include "my.h"

void move_cells(char **env)
{
	while (*env) {
		*(env) = *(env + 1);
		env++;
	}
}

char **modify_unenv(char **env, char **tab)
{
	if (len_tab(tab) == 1)
		my_error("unsetenv: Too few arguments.\n");
	for (int i = 0; tab[i]; i++) {
		for (int j = 0; env[j]; j++) {
			if (!strncmp(tab[i], env[j], strlen(tab[i]))
				&& strlen(env[j]) > strlen(tab[i])
				&& env[j][strlen(tab[i])] == '=') {
				move_cells(env + j);
				break;
			}
		}
	}
	return (env);
}
