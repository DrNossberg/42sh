/**
* @file my_strlen.c
* @author Antoine Orion
* @author Julien Dubocage
*/

#include <unistd.h>

int my_strlen(char *str)
{
	int i = 0;

	for (; str[i] != '\0'; i++);
	return (i);
}
