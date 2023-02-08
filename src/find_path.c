/**
* @file find_path.c
* @author Antoine Orion
* @author Julien Dubocage
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"

int find_path(char **env, int i)
{
	int j = 0;
	int k = 0;
	char *find = "PATH";

	while (j < 4) {
		if (env[i][j] == find[k])
			k++;
		j++;
	}
	return (k);
}

char *find_env(char **env)
{
	int i = 0;
	int k = 0;

	while (env[i] != NULL) {
		k = find_path(env, i);
		if (k == 4)
			return (env[i]);
		i++;
	}
	return (NULL);
}

int nbr_path(char *str)
{
	int i = 0;
	int nb = 0;

	while (str[i] != '\0') {
		if (str[i] == ':')
			nb++;
		i++;
	}
	if (nb == 0)
		return (1);
	return (nb);
}

char *check_path_bis(char *str, int k)
{
	char *cut_str = NULL;

	if (str[k - 1] == '/') {
		str[k] = '\0';
		cut_str = strndup(str, k);
	} else {
		str[k] = '/';
		str[k + 1] = '\0';
		cut_str = strndup(str, k + 1);
	}
	free(str);
	return (cut_str);
}

char **check_path(char *p)
{
	char **tab = malloc(sizeof(char *) * (nbr_path(p) + 1));
	int i = 4;
	int j = 0;
	int k = 0;

	if (!check_coma(p))
		return (without_coma(tab, p));
	while (p[i] != '\0') {
		if (p[i] == ':' || p[i] == '=') {
			i++;
			tab[j] = malloc(sizeof(char) * strlen(p));
			for (k = 0; (p[i] >= '!' && p[i] < ':')
				|| (p[i] > ':' && p[i] <= '~'); i++, k++)
				tab[j][k] = p[i];
			tab[j] = check_path_bis(tab[j], k);
			j++;
		} else
			i++;
	}
	tab[--j] = NULL;
	return (tab);
}
