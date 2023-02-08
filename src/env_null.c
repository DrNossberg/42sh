/**
* @file env_null.c
* @author Antoine Orion
* @author Julien Dubocage
*/

#include "my.h"
#include "my_exit.h"

/**
 * @fn int env_null(char **tab, char **env, nb_exit_t **buffer)
 * @brief Checks if the command is valid
 * @param tab Array of strings containing the command
 * @param env Array of environment variables used by the shell
 * @param buffer Pointer to a structure that holds info about the current shell's state
*/
int env_null(char **tab, char **env, nb_exit_t **buffer)
{
	if (check_prog_two(tab, env, buffer) == 0)
		return (0);
	if (check_v(tab) == 1 && tab[0][0] == '/') {
		my_error(tab[0]);
		my_error(": Permission denied.\n");
		buffer[0]->nb_exit = 1;
		return (0);
	} else {
		my_error(tab[0]);
		my_error(": Command not found.\n");
		buffer[0]->nb_exit = 1;
	}
	return (0);
}
