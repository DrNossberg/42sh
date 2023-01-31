/*
** EPITECH PROJECT, 2017
** PSU_42sh_2017
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
	env[i] = my_strdup(src);
	return (env);
}