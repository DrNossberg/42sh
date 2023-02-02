/*
** Cnam, en partenariat avec l'ITII Alsace, 2023
** Projet :
**    42sh
** Author :
**    Julien  DUBOCAGE
**    Antoine ORION
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
