/*
** EPITECH PROJECT, 2018
** multi_launch
** File description:
** .c
*/

#include "../include/my.h"
#include "../include/my_exit.h"

int check_save(char *part_path, char **tab, char **env, nb_exit_t **buffer)
{
	int pid = fork();

	if (pid == 0) {
		if (access(part_path, X_OK) == -1) {
			my_error(tab[0]);
			my_error(": Permission denied.\n");
			exit(1);
		}
		if (execve(part_path, tab, env) == -1) {
			my_error(tab[0]);
			my_error(": Exec format error. Wrong Architecture.\n");
			exit(1);
		}
	} else
		buffer[0]->nb_wait[buffer[0]->nb_wait_choice] = pid;
	return (0);
}

int permi_for_instru(char **tab, char **env, nb_exit_t **buffer)
{
	int simple = 0;

	if (check_v(tab) == 1 && tab[0][0] == '/') {
		my_error(tab[0]);
		my_error(": Permission denied.\n");
		buffer[0]->nb_exit = 1;
		return (0);
	}
	if (!access(tab[0], F_OK) && !access(tab[0], X_OK)) {
		check_save(tab[0], tab, env, buffer);
		simple = 1;
	}
	if (!simple) {
		my_error(tab[0]);
		my_error(": Command not found.\n");
		buffer[0]->nb_exit = 1;
	}
	return (0);
}

int check_prog(char **part_path, char **tab, char **env, nb_exit_t **buffer)
{
	int j = 0;
	int save_acc = 0;
	struct stat status;

	if (check_prog_two(tab, env, buffer) == 0)
		return (0);
	for (; part_path[j]; j++) {
		save_acc = access(part_path[j], F_OK);
		if (save_acc == 0 && lstat(part_path[j], &status) != -1)
			return (check_save(part_path[j], tab, env, buffer));
	}
	return (permi_for_instru(tab, env, buffer));
}

char **lauch_cmd(char *save, char **env, nb_exit_t **buffer)
{
	char **pipe = my_str_array(save, '|');

	if (check_pipe_error(pipe, buffer))
		return (env);
	env = launch_pipe(env, pipe, buffer);
	return (env);
}

nb_exit_t *init_nb_exit(void)
{
	nb_exit_t *new_element = malloc(sizeof(nb_exit_t));

	if (!new_element)
		return (NULL);
	new_element->nb_exit = 0;
	new_element->n_of_alias = 0;
	new_element->nb_wait = NULL;
	new_element->nb_wait_choice = 0;
	new_element->part_p = NULL;
	return (new_element);
}
