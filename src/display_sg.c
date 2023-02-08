/**
* @file display_sg.c
* @author Antoine Orion
* @author Julien Dubocage
*/

#include "my.h"
#include "my_exit.h"
#include "../include/my_exit.h"

/**
 * @fn void whoole_for_wait(int nb_of_pipe, nb_exit_t **buffer)
 * @brief Waits for the child processes to finish
 * @param nb_of_pipe Number of pipes in the command
 * @param buffer Pointer to a structure that holds info about the current shell's state
 * @return void
*/
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

/**
 * @fn void display_sg(int status, nb_exit_t **buffer)
 * @brief Displays the signal that caused the child process to terminate
 * @param status Status of the child process
 * @param buffer Pointer to a structure that holds info about the current shell's state
 * @return void
*/
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
