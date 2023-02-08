/**
* @file check_before_execve.c
* @author Antoine Orion
* @author Julien Dubocage
*/

#include "my.h"
#include "my_exit.h"

void display_error(char *tab, char *msg, nb_exit_t **buffer)
{
	my_error(tab);
	my_error(msg);
	buffer[0]->nb_exit = 1;
}

int check_prog_two(char **tab, char **env, nb_exit_t **buffer)
{
	if (!strncmp("./", tab[0], 2)) {
		if (!check_v(tab) && !access(tab[0], F_OK)) {
			check_save(tab[0], tab, env, buffer);
			return (0);
		}
		if (access(tab[0], F_OK) == -1)
			display_error(tab[0], ": Command not found.\n", buffer);
		else
			display_error(tab[0], ": Permission denied.\n", buffer);
		return (0);
	}
	if (!check_v(tab) && !check_f(tab) && tab[0][0] == '/') {
		check_save(tab[0], tab, env, buffer);
		return (0);
	}
	return (1);
}
