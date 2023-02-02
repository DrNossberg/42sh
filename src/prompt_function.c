/*
** Cnam, en partenariat avec l'ITII Alsace, 2023
** Projet :
**    42sh
** Author :
**    Julien  DUBOCAGE
**    Antoine ORION
** File description:
** contains some of the subfunctions for the minishell1
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdio.h>
#include "my.h"

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
