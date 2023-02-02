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
