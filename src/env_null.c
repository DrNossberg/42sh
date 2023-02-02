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

#include "my.h"
#include "my_exit.h"

int env_null(char **tab, char **env, nb_exit_t **buffer)
{
	if (check_prog_two(tab, env, buffer) == 0)
		return (0);
	if (check_v(tab) == 1 && tab[0][0] == '/') {
		my_error(tab[0]);
		my_error(": Permission denied.\n");
		buffer[0]->nb_exit = 1;
		return (0);
	} else {
		my_error(tab[0]);
		my_error(": Command not found.\n");
		buffer[0]->nb_exit = 1;
	}
	return (0);
}
