/**
* @file prompt_function.c
* @author Antoine Orion
* @author Julien Dubocage
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdio.h>
#include "my.h"

/**
 * @fn void prompt_way(void)
 * @brief Displays the current working directory in the shell prompt
 * @return void
*/
void prompt_way(void)
{
	char **arway;
	char *way = NULL;

	way = getcwd(way, 0);
	if (!way)
		perror("getcwd fail");
	arway = my_cutstr_to_ar(way, '/');
	printf("[%s%s]$", "\x1b[0m", arway[my_arlen(arway) - 1]);
	fflush(stdout);
	free(way);
	free(arway);
}
