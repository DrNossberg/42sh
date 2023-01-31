/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** contain function to free
*/

#include <stdlib.h>

void clean_ar(char **ar)
{
	for (int i = 0; ar[i]; i++)
		free(ar[i]);
	free(ar);
}
