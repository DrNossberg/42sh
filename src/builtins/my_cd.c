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

#include "../../include/my.h"
#include "../../include/my_exit.h"

char **cd_less(char *buffer, char **env, int i, nb_exit_t **buf)
{
	char **tab = NULL;
	char *oldpwd = "setenv ";
	char *save = NULL;

	save = strdup(buffer);
	if (i == 0) {
		getcwd(buffer, 255);
		save = strdup(buffer);
		buffer = env[find_line(env, "OLDPWD")];
		buffer = buffer + strlen("OLDPWD") + 1;
		chdir(buffer);
	}
	oldpwd = my_strncat(oldpwd, "OLDPWD ", 7);
	oldpwd = my_strncat(oldpwd, save, strlen(save));
	tab = my_str_to_word_array(oldpwd);
	env = modify_env(env, tab, buf);
	return (env);
}

char **my_wave(char **env, char **tab, char *buffer, nb_exit_t **buf)
{
	buffer = only_cd(buffer, env, tab);
	env = cd_less(buffer, env, 1, buf);
	return (env);
}

char **my_dash(char **env, char **tab, char *buffer, nb_exit_t **buf)
{
	tab = tab;
	for (int j = 0; env[j]; j++) {
		if (verify_setenv(env, "OLDPWD=") == 0) {
			env = cd_less(buffer, env, 0, buf);
			return (env);
		} else
			my_error("cd: Not a directory.\n");
		return (env);
	}
	return (env);
}

char **my_cd_error(char **env, char **tab, nb_exit_t **buffer)
{
	if (access(tab[1], F_OK) == -1) {
		my_error(tab[1]);
		my_error(": Not a directory.\n");
		buffer[0]->nb_exit = 1;
		return (env);
	} else if (access(tab[1], X_OK) == -1 && check_cd(tab[1])) {
		my_error(tab[1]);
		my_error(": Permission denied.\n");
		buffer[0]->nb_exit = 1;
		return (env);
	}
	if (chdir(tab[1]) == -1) {
		my_error(tab[1]);
		my_error(": Not a directory.\n");
		buffer[0]->nb_exit = 1;
		return (env);
	}
	return (env);
}

char **my_cd(char **env, char **tab, nb_exit_t **buf)
{
	char *buffer = malloc(sizeof(char) * 256);

	buf[0]->nb_exit = 0;
	buffer[255] = '\0';
	if (len_tab(tab) > 2) {
		my_error("cd: Too many arguments.\n");
		return (env);
	}
	if (tab[1] == NULL || ((strncmp(tab[1], "~", 1) == 0)
		&& tab[1][1] == '\0'))
		return (my_wave(env, tab, buffer, buf));
	else if (strncmp(tab[1], "-", 1) == 0 && tab[1][1] == '\0')
		return (my_dash(env, tab, buffer, buf));
	getcwd(buffer, 255);
	env = cd_less(buffer, env, 1, buf);
	return (my_cd_error(env, tab, buf));
}
