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

#include "my.h"

char *epurstring(char *str)
{
	int i = 0;

	if (!strlen(str))
		return (str);
	for (; (*str == ' ' || *str == '\t') && *str; str++);
	i = strlen(str) - 1;
	for (; (str[i] == ' ' || str[i] == '\t') && i && str[i]; i--);
	str[i + 1] = '\0';
	return (str);
}
