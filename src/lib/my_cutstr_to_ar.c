/**
* @file my_cutstr_to_ar.c
* @author Antoine Orion
* @author Julien Dubocage
*/

#include <stdlib.h>
#include "my.h"

char **my_cutstr_to_ar(char *str, char s)
{
	char **array;
	int nb_word  = 0;
	int len_str  = my_strlen(str);
	int j = 0;
	int i = 0;

	for (; i <= len_str; i++) {
		if (str[i] == s || str[i] == '\0')
			nb_word++;
	}
	array = malloc(sizeof(char *) * (nb_word + 1));
	for (i = 0; i < nb_word; i++, str++) {
		for (j = 0; str[j] != s && str[j] != '\0'; j++);
		array[i] = malloc(sizeof(char) * j + 1);
		for (j = 0; *str != s && *str != '\0';	str++, j++)
			array[i][j] = *str;
		array[i][j] = '\0';
	}
	array[i] = NULL;
	return(array);
}