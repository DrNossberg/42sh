/*
** Cnam, en partenariat avec l'ITII Alsace, 2023
** Projet :
**    42sh
** Author :
**    Julien  DUBOCAGE
**    Antoine ORION
** File description:
** Created by davy.henry,
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "my_exit.h"
#include "my.h"

int number_arg(char **str)
{
	int i = 0;

	for (; str[i]; i++);
	return (i);
}

static void print_dollar(char const *env, size_t a)
{
	for (size_t i = a + 1; env[i]; i++)
		printf("%c", env[i]);
}

static void manage_dollar(char *str, char **env, nb_exit_t *buffer)
{
	size_t a = strlen(str);

	if (a == 1) {
		printf("$");
		return;
	}
	if (str[1] == '?') {
		printf("%d", buffer->nb_exit);
		return;
	}
	str++;
	a--;
	for (int i = 0; env[i]; i++)
		if (!strncmp(str, env[i], a))
			print_dollar(env[i], a);
}

static void check_print(char *str, char **env, nb_exit_t *buffer)
{
	(str[0] == '"') ? str++ : str;
	for (int i = 0; str[i]; i++)
		if (str[i] == '"')
			str[i] = '\0';
	if (str[0] == '$') {
		manage_dollar(str, env, buffer);
		return;
	}
	printf("%s", str);
}

char **my_echo(char **env, char **str, nb_exit_t **buffer)
{
	int a = number_arg(str);
	int p = 0;

	if (a == 1) {
		printf("\n");
		return (env);
	}
	for (int i = 1; str[i]; i++)
		for (int j = 0; str[i][j]; j++)
			p = (str[i][j] == '"') ? p + 1 : p;
	if (p % 2 != 0) {
		write(2, "Unmatched '\"'\n", 14);
		return (env);
	}
	for (int i = 1; str[i]; i++) {
		if (i != 1)
			printf(" ");
		check_print(str[i], env, *buffer);
	}
	printf("\n");
	return (env);
}
