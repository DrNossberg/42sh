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

#include "../include/my.h"
#include "../include/my_exit.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <dirent.h>

int check_v(char **tab)
{
	struct stat statbuf;

	if (!tab || !tab[0])
		return (0);
	if (stat(tab[0], &statbuf) == -1)
		return (0);
	if (S_ISDIR(statbuf.st_mode))
		return (1);
	else
		return (0);
}

int check_cd(char *tab)
{
	struct stat statbuf;

	if (!tab)
		return (0);
	if (stat(tab, &statbuf) == -1)
		return (0);
	if (S_ISDIR(statbuf.st_mode))
		return (1);
	else
		return (0);
}

int check_f(char **tab)
{
	if (access(tab[0], X_OK) == 0)
		return (0);
	return (1);
}

void multi_error(char **tab, nb_exit_t **buffer)
{
	my_error(tab[0]);
	my_error(": Command not found.\n");
	buffer[0]->nb_exit = 1;
}

void test(int i)
{
	i = i;
	write(1, "\n$>", 3);
}
