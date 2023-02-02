/*
** Cnam, en partenariat avec l'ITII Alsace, 2023
** Projet :
**    42sh
** Author :
**    Julien  DUBOCAGE
**    Antoine ORION
** File description:
** Created by pierro,
*/
#include "../include/my.h"
#include "../include/my_exit.h"

char **my_cwd(char **env, char **tab, nb_exit_t **buffer)
{
	int i = find_line(env, "PWD");
	char *str = strdup(env[i]);

	if (str == NULL) {
		dprintf(2, "cwd not found\n");
		return (env);
	}
	for (int i = 4; str[i]; i++)
		write(1, &str[i], 1);
	write(1, "\n", 1);
	tab = tab;
	buffer = buffer;
	return (env);
}