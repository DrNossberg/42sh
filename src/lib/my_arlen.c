/*
** EPITECH PROJECT, 2018
** my_arlen
** File description:
** return the length of an array
*/

#include <stdio.h>

int my_arlen(char **array)
{
	int i;

	for (i = 0; array[i]; i++);
	return (i);
}