/**
* @file my_env.c
* @author Antoine Orion
* @author Julien Dubocage
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
