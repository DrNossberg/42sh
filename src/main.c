/**
* @file main.c
* Main file of the project
* @author Antoine Orion
* @author Julien Dubocage
*/

#include "my.h"
#include "my_struct.h"
#include "my_exit.h"
#include "tokenizer.h"
#include "lexer.h"

/**
 * @fn char **main_tree(char **t, char **env, nb_exit_t **buffer)
 * @brief Run an external program that is not a shell built-in
 * @param t array containing the command and its arguments
 * @param env Array of environment variables used by the shell
 * @param buffer Pointer to a structure that holds info about the current shell's state
 * 
*/
char **main_tree(char **t, char **env, nb_exit_t **buffer)
{
	char *path = find_env(env);
	char **part_p = NULL;

	if (path) {
		if (strlen(t[0]) == 0)
			return (env);
		if (strlen(t[0]) != 0) {
			part_p = check_path(path);
			for (int j = 0; part_p[j]; j++) {
				part_p[j] = my_strncat(part_p[j], t[0],
					strlen(t[0]));
			}
			check_prog(part_p, t, env, buffer);
			clean_ar(part_p);
		} else
			multi_error(t, buffer);
	} else
		env_null(t, env, buffer);
	return (env);
}

/**
 *  
 * @fn char **launch_pipe(char **env, char **save_instru, nb_exit_t **buffer)
 * @brief Execute piped commands
 * Handles piped commands, redirecting input and output as required
 * @param env Array of environment variables used by the shell
 * @param save_instru Array of commands to be executed in a pipeline
 * @param buffer Pointer to a structure that holds info about the current shell's state
 * @return Array of environment variables after execution of the pipeline
*/
char **launch_pipe(char **env, char **save_instru, nb_exit_t **buffer)
{
	int pipefd[2];
	int nb_of_pipe = count_pipe(save_instru) + 4;

	buffer[0]->nb_wait_choice = 0;
	buffer[0]->nb_wait = pipe_with_wait(nb_of_pipe);
	for (int i = 0, k = 0; save_instru[i]; i++, k = 0) {
		buffer[0]->nb_wait_choice = i;
		pipefd[0] = dup(0);
		pipefd[1] = dup(1);
		save_instru[i] = my_parse_instru(save_instru[i], buffer, &k);
		if (multi_pipe(0, i, save_instru) == -1)
			return (env);
		if (strlen(save_instru[i]) != 0 && !k)
			env = lauch_simple_cmd(env, save_instru[i], buffer);
		dup2(pipefd[0], 0);
		dup2(pipefd[1], 1);
	}
	whoole_for_wait(nb_of_pipe, buffer);
	return (env);
}

/**
 * @fn char **lauch_cmd(char *save, char **env, nb_exit_t **buffer)
 * Finds the bultin function associated with the command and calls it.
 * If the command is not a bultin, the main_tree function is called to execute the external command using the operating system.
 * @brief Finds and call the bultin command or execute the external command using the operating system.
 * @param env Array of environment variables used by the shell
 * @param save command string
 * @param buffer Pointer to a structure that holds info about the current shell's state
 * @return updated environment variables array.
*/
char **lauch_simple_cmd(char **env, char *save, nb_exit_t **buffer)
{
	int prog = 0;
	char **tab = my_str_to_word_array(save);

	for (int k = 0; bultin[k].lt != NULL; k++)
		if ((strncmp(bultin[k].lt, tab[0],
			strlen(bultin[k].lt)) == 0) &&
			tab[0][strlen(bultin[k].lt)] == '\0') {
			env = bultin[k].sf(env, tab, buffer);
			prog = 1;
		}
	if (!prog)
		env = main_tree(tab, env, buffer);
	return (env);
}

/**
 *
 * @fn char **main_deux(char *save, char **env, nb_exit_t **buffer)
 * Handles the execution of multiple commands separated by a semicolon (;) in the user input
 * @brief Function to handle multiple commands in the user input
 * @param save User input to be executed as a command or multiple commands
 * @param env Array of environment variables used by the shell
 * @param buffer Pointer to a structure that holds info about the current shell's state
 * @return Array of environment variables after execution of the user input
*/
char **main_deux(char *save, char **env, nb_exit_t **buffer)
{
	char **t;
	char *test = NULL;

	save = check_alias(*buffer, save);
	t = my_str_array(save, ';');
	if (t[0] == NULL) {
		buffer[0]->nb_exit = 0;
		return (env);
	}
	for (int i = 0; t[i]; i++) {
		if (strlen(t[i])) {
			test = epurstring(t[i]);
			env = lauch_cmd(test, env, buffer);
		}
	}
	return (env);
}

/**
 * @fn int main(int ac, char **av, char **env)
 * Handles the main loop that reads user input, calls functions to execute commands and handles system signals
 * @brief Main project's function 
 * @param ac Number of arguments
 * @param av Array of arguments
 * @param env Array of environment variables used by the shell
 * 
*/
int main(int ac, char **av, char **env)
{
	char *save = NULL;
	nb_exit_t *buffer = init_nb_exit();

	ac = ac;
	av = av;
	while (1) {
		prompt_way();
		signal(SIGINT, test);
		save = get_next_line(0);
		if (save == NULL ||
			(!strncmp("exit", save, 4) && save[4] == '\0')) {
			return (buffer->nb_exit);
		}
		save = epurstring(save);
		if (strlen(save) != 0)
			env = main_deux(save, env, &buffer);
		env = test1(env);
	}
}
