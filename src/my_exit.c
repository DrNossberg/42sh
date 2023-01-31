/*
** EPITECH PROJECT, 2018
** my_exit
** File description:
** .c
*/

#include "my.h"

char **my_exit(char **env, char **tab, int *nb_exit)
{
	env = env;
	tab = tab;
	nb_exit = nb_exit;
	write(1, "exit\n", 5);
	return (env);
}
