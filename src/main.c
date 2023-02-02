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
#include "my_struct.h"
#include "my_exit.h"
#include "tokenizer.h"
#include "lexer.h"

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
