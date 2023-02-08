/**
* @file setenv.c
* @author Antoine Orion
* @author Julien Dubocage
*/

#include "../include/my.h"
#include "../include/my_exit.h"
#include "../../include/my_exit.h"

char **find_setenv(char **save, char **tab)
{
	int i = find_line(save, tab[1]);
	int j = 0;
	char *save_re = malloc(sizeof(char) * (strlen(save[i]) + 1));

	save_re[strlen(save[i])] = '\0';
	while (save[i][j] != '=') {
		save_re[j] = save[i][j];
		j++;
	}
	save_re[j] = '\0';
	save_re = my_strncat(save_re, "=", 1);
	save[i] = my_strncat(save_re, tab[2], strlen(tab[2]));
	return (save);
}

char **modify_save(char **env, char **tab, char **save, int i)
{
	if (len_tab(tab) > 1 && len_tab(tab) < 4) {
		tab[1] = my_strncat(tab[1], "=", 1);
		if (verify_setenv(env, tab[1]) != 0) {
			save[i] = tab[1];
			save[i + 1] = NULL;
			if (len_tab(tab) == 3)
				find_setenv(save, tab);
		} else if (len_tab(tab) == 2)
			(save[find_line(save, tab[1])]) = tab[1];
		else if (len_tab(tab) == 3)
			find_setenv(save, tab);
	} else
		save[i] = NULL;
	return (save);
}

int check_alphanum_bis(char *tab)
{
	while (*(tab)) {
		if ((*tab >= '0' && *tab <= '9') || (*tab >= 'A' && *tab <= 'Z')
			|| (*tab >= 'a' && *tab <= 'z'))
			tab++;
		else
			return (1);
	}
	return (0);
}

int check_alphanum(char **tab, nb_exit_t **buffer)
{
	buffer[0]->nb_exit = 0;
	if ((tab[1][0] > '0' || tab[1][0] < '9')
		&& (tab[1][0] < 'A' || tab[1][0] > 'Z')
		&& (tab[1][0] < 'a' || tab[1][0] > 'z')) {
		my_error(tab[0]);
		my_error(": Variable name must begin with a letter.\n");
		buffer[0]->nb_exit = 1;
		return (1);
	}
	if (check_alphanum_bis(tab[1]) != 0) {
		my_error(tab[0]);
		my_error(": Variable name must ");
		my_error("contain alphanumeric characters.\n");
		buffer[0]->nb_exit = 1;
		return (1);
	}
	if (len_tab(tab) > 3) {
		my_error("setenv: Too many arguments.\n");
		buffer[0]->nb_exit = 1;
	}
	return (0);
}

char **modify_env(char **env, char **tab, nb_exit_t **buffer)
{
	int i = 0;
	int l_e = len_tab(env);
	int l_t = len_tab(tab);
	char **save = malloc(sizeof(char *) * (l_e + l_t + 2));

	save[len_tab(env) + len_tab(tab)] = NULL;
	if (len_tab(tab) == 1) {
		my_show_word_array(env);
		return (env);
	}
	if (check_alphanum(tab, buffer) != 0)
		return (env);
	while (i < len_tab(env)) {
		save[i] = env[i];
		i++;
	}
	return (modify_save(env, tab, save, i));
}
