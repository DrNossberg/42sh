/*
** EPITECH PROJECT, 2018
** my_strncat
** File description:
** .c
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "my.h"

char *my_strncat(char *d, char *s, int nb)
{
	int i = 0;
	int j = 0;
	int size_dest = check_n(d, 1);
	char *save = malloc(sizeof(char) * (check_n(d, 1) + check_n(s, 1) + 1));

	if (save == NULL)
		return (NULL);
	save[check_n(d, 1) + check_n(s, 1)] = '\0';
	while (j != size_dest) {
		save[j] = d[j];
		j++;
	}
	save[j] = '\0';
	while (s[i] != '\0' && i < nb) {
		save[size_dest + i] = s[i];
		i++;
	}
	save[size_dest + i] = '\0';
	return (save);
}
