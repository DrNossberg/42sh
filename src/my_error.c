/*
** EPITECH PROJECT, 2018
** my_error
** File description:
** .c
*/

#include "my.h"

void my_error(char *str)
{
	write(2, str, strlen(str));
}
