/**
* @file my_error.c
* @author Antoine Orion
* @author Julien Dubocage
*/

#include "my.h"

void my_error(char *str)
{
	write(2, str, strlen(str));
}
