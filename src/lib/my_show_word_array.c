/**
* @file my_show_word_array.c
* @author Antoine Orion
* @author Julien Dubocage
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
