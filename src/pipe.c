/**
* @file pipe.c
* Utils functions for pipes
* @author Antoine Orion
* @author Julien Dubocage
*/

#include "../include/my.h"
#include "../include/my_exit.h"

/**
 * @fn int display_error_pipe(char **pipe, nb_exit_t **buffer)
 * @brief display_error_pipe displays an error message for an invalid pipe.
 * @param pipe pipe command
 * @param buffer Pointer to a structure that holds info about the current shell's state
 * @return 0 to indicate error.
*/
int display_error_pipe(char **pipe, nb_exit_t **buffer)
{
	pipe = pipe;
	my_error("Invalid null command.\n");
	buffer[0]->nb_exit = 1;
	return (0);
}

/**
 * @fn int check_pipe_error(char **pipe, nb_exit_t **buffer)
 * @brief check_pipe_error checks for errors in the pipeline.
 * @param pipe array of commands to be executed in pipeline
 * @param buffer Pointer to a structure that holds info about the current shell's state
 * @return 0 on success, otherwise error code is returned
*/
int check_pipe_error(char **pipe, nb_exit_t **buffer)
{
	int i = 0;

	for (; pipe[i]; i++) {
		if (!strlen(pipe[i]))
			return (display_error_pipe(pipe, buffer));
	}
	return (0);
}

/**
 * @fn int *pipe_with_wait(int nb_of_pipe)
 * The function allocates an integer array with the size of nb_of_pipe and sets all values to -1
 * @brief Allocates and initializes an array to store information about pipes
 * @param nb_of_pipe Number of pipes
 * @return Pointer to the allocated and initialized array
*/
int *pipe_with_wait(int nb_of_pipe)
{
	int *nb_multi_wait = malloc(sizeof(int) * (nb_of_pipe + 1));

	if (!nb_multi_wait)
		return (NULL);
	nb_multi_wait[nb_of_pipe] = -1;
	for (int i = 0; i < nb_of_pipe; i++)
		nb_multi_wait[i] = -1;
	return (nb_multi_wait);
}

/**
 * @fn int count_pipe(char **pipe)
 * @brief Counts the number of pipes in a piped command string
 * @param pipe Array of piped commands
 * @return Number of pipes in the piped command string
*/
int count_pipe(char **pipe)
{
	int i = 0;

	for (; pipe[i]; i++);
	return (i - 1);
}

/** 
 * @fn int multi_pipe(int input, int i, char **save_instru)
 * Performs multi-piping functionality in shell by creating pipes and duplicating file descriptors
 * @brief Implement multi-piping functionality in shell
 * @param input The input file descriptor
 * @param i The index of the current command in the piped commands array
 * @param save_instru Array of piped commands read from user input
 * @return 0 on success, -1 on failure to create pipes
*/
int multi_pipe(int input, int i, char **save_instru)
{
	static int pipe_array[2];

	if (i)
		input = pipe_array[0];
	if (pipe(pipe_array) == -1)
		return (-1);
	if (save_instru[i + 1]) {
		dup2(pipe_array[1], 1);
		close(pipe_array[1]);
	}
	dup2(input, 0);
	return (0);
}
