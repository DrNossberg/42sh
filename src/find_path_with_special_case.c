/*
** EPITECH PROJECT, 2018
** special_case
** File description:
** .c
*/

#include "../include/my.h"

char **without_coma(char **tab, char *path)
{
	tab[0] = my_strdup(path + 5);
	tab[0] = check_path_bis(tab[0], strlen(path + 5));
	tab[1] = NULL;
	return (tab);
}

int check_coma(char *str)
{
	int i = 0;
	int nb = 0;

	while (str[i] != '\0') {
		if (str[i] == ':')
			nb++;
		i++;
	}
	return (nb);
}
