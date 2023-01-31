/*
** EPITECH PROJECT, 2018
** my_cd
** File description:
** .c
*/

#include "../include/my.h"
#include "../include/my_exit.h"

char **test1(char **env)
{
	int i = find_line(env, "PWD");
	char *buffer = malloc(sizeof(char) * 256);

	getcwd(buffer, 255);
	env[i] = strdup("PWD=");
	env[i] = my_strncat(env[i], buffer, strlen(buffer));
	return (env);
}
