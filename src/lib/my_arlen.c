/**
* @file my_arlen.c
* @author Antoine Orion
* @author Julien Dubocage
*/

#include <stdio.h>

int my_arlen(char **array)
{
	int i;

	for (i = 0; array[i]; i++);
	return (i);
}