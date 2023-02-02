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

#include "my.h"

int len_tab(char **str)
{
	int i = 0;

	while (str[i] != NULL)
		i++;
	return (i);
}

int verify_setenv(char **env, char *tab)
{
	int i = 0;
	unsigned int j = 0;
	unsigned int k = 0;

	while (env[i] != NULL) {
		j = 0;
		k = 0;
		while (env[i][j] != '\0' && j < strlen(tab)) {
			if (env[i][j] == tab[k] && (j < strlen(tab)))
				k++;
			j++;
		}
		if (k == strlen(tab))
			return (0);
		i++;
	}
	return (1);
}

int find_line(char **save, char *tab)
{
	int i = 0;
	unsigned int j = 0;
	unsigned int k = 0;

	while (save[i]) {
		j = 0;
		k = 0;
		while (save[i][j] != '\0' && j < strlen(tab)) {
			if (save[i][j] == tab[j])
				k++;
			j++;
		}
		if (k == strlen(tab))
			return (i);
		i++;
	}
	return (0);
}
