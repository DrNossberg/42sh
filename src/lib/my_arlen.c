/*
** Cnam, en partenariat avec l'ITII Alsace, 2023
** Projet :
**    42sh
** Author :
**    Julien  DUBOCAGE
**    Antoine ORION
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