/**
* @file my_str_array.c
* @author Antoine Orion
* @author Julien Dubocage
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"

int nbr_word(char *str)
{
	int i = 0;
	int nb = 0;

	while (str[i] != '\0') {
		if (str[i] != '\t' && str[i] != ' ') {
			while ((str[i] >= '!' && str[i] <= '~') &&
			(str[i] != ' ' && str[i] != '\t')) {
				i++;
			}
			nb++;
		}
		if (str[i] != '\0')
			i++;
	}
	nb--;
	return (nb);
}

char **my_str(int j, int k, char **tab, char *str)
{
	int i = 0;

	while (str[i] != '\0') {
		if (str[i] != '\t' && str[i] != ' ') {
			tab[j] = malloc(sizeof(char) * (strlen(str) + 1));
			while ((str[i] >= '!' && str[i] <= '~')
			&& (str[i] != ' ' && str[i] != '\t')) {
				tab[j][k] = str[i];
				i++;
				k++;
			}
			tab[j][k] = '\0';
			k = 0;
			j++;
		}
		if (str[i] != '\0')
			i++;
	}
	tab[j] = NULL;
	return (tab);
}

char **my_str_to_word_array(char *str)
{
	char **tab = malloc(sizeof(char *) * (nbr_word(str) + 2));

	return (my_str(0, 0, tab, str));
}

char **my_str_array(char *str, char s)
{
	char **array = NULL;
	int nb_word = 0;
	int len_str = strlen(str);
	int j = 0;
	int i = 0;

	for (; i <= len_str; i++)
		if (str[i] == s || str[i] == '\0')
			nb_word++;
	array = malloc(sizeof(char *) * (nb_word + 1));
	for (i = 0; i < nb_word; i++, str++) {
		for (j = 0; str[j] != s && str[j] != '\0'; j++);
		array[i] = malloc(sizeof(char) * j + 1);
		for (j = 0; *str != s && *str != '\0';  str++, j++)
			array[i][j] = *str;
		array[i][j] = '\0';
	}
	array[i] = NULL;
	return (array);
}
