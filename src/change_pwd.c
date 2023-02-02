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

char **change_pwd(char **env)
{
	int i = find_line(env, "PWD");
	char *str = NULL;
	char *pwd = strdup("PWD=");
	char *src = NULL;

	str = getcwd(str, 255);
	if (str == NULL)
		return (env);
	src = my_strncat(pwd, str, (int)(strlen(str)));
	env[i] = strdup(src);
	return (env);
}