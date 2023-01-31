/*
** EPITECH PROJECT, 2018
** functions
** File description:
** .c
*/

#include <unistd.h>

int my_strlen(char *str)
{
	int i = 0;

	for (; str[i] != '\0'; i++);
	return (i);
}
