/**
* @file epurestring.c
* @author Antoine Orion
* @author Julien Dubocage
*/

#include "my.h"

/**
 * @fn char *epurstring(char *str)
 * @brief Remove the spaces at the beginning and at the end of a string
 * @param str The string to epure
*/
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
