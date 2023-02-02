/*
** Cnam, en partenariat avec l'ITII Alsace, 2023
** Projet :
**    42sh
** Author :
**    Julien  DUBOCAGE
**    Antoine ORION
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
