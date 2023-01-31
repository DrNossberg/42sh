/*
** EPITECH PROJECT, 2018
** functions
** File description:
** .c
*/

#include <unistd.h>

void my_putchar(char c)
{
	write(1, &c, 1);
}

void my_putstr(char *src)
{
	int i = 0;

	while (src[i] != '\0') {
		my_putchar(src[i]);
		i++;
	}
}
