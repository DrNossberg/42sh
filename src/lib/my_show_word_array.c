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
#include <stdlib.h>
#include <stdio.h>
#include "my.h"

void my_show_word_array(char **tab)
{
	int i = 0;

	while (tab[i] != NULL) {
		write(1, tab[i], strlen(tab[i]));
		write(1, "\n", 1);
		i++;
	}
}
