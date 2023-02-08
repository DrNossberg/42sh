/**
* @file clean_array.c
* @author Antoine Orion
* @author Julien Dubocage
*/

#include <stdlib.h>

/**
 * @fn void clean_ar(char **ar)
 * @brief Frees the memory allocated to an array of strings
 * @param ar Array of strings
 * @return void
*/
void clean_ar(char **ar)
{
	for (int i = 0; ar[i]; i++)
		free(ar[i]);
	free(ar);
}
