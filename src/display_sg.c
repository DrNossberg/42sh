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

#include "my.h"
#include "my_exit.h"
#include "../include/my_exit.h"

void whoole_for_wait(int nb_of_pipe, nb_exit_t **buffer)
{
	int status;

	for (int i = 0; i < nb_of_pipe && buffer[0]->nb_wait[i] != -1; i++) {
		waitpid(buffer[0]->nb_wait[i], &status, 0);
		if ((WTERMSIG(status) && WIFSIGNALED(status)))
			display_sg(status, buffer);
		else if (!buffer[0]->nb_exit)
			buffer[0]->nb_exit = WEXITSTATUS(status);
		else
			buffer[0]->nb_exit = WEXITSTATUS(status);
	}
}

void display_sg(int status, nb_exit_t **buffer)
{
	if (WTERMSIG(status) == SIGSEGV) {
		my_error("Segmentation fault\n");
		if (!buffer[0]->nb_exit)
			buffer[0]->nb_exit = 139;
		return;
	}
	if (WTERMSIG(status) == SIGFPE) {
		my_error("Floating exception\n");
		if (!buffer[0]->nb_exit)
			buffer[0]->nb_exit = 136;
		return;
	}
}
