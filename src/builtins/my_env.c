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

char **my_env(char **env, char **tab)
{
	if (tab[1] != NULL) {
		my_error("env: '");
		my_error(tab[1]);
		my_error("': No such file or directory\n");
		return (env);
	}
	my_show_word_array(env);
	return (env);
}
