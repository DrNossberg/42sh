/*
** EPITECH PROJECT, 2017
** my_strdup.c
** File description:
** .c
*/

#include <stdlib.h>
#include "my.h"

char *my_strdup(char *src)
{
	char *str;
	int i = 0;
	int size_src = my_strlen(src);

	str = malloc(sizeof(char) * (size_src + 1));
	while (i < size_src) {
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
