/*
** EPITECH PROJECT, 2018
** my
** File description:
** .h
*/

#ifndef _MY_H
	# define _MY_H
	#include <dirent.h>
	#include <sys/stat.h>
	#include <errno.h>
	#include <string.h>
	#include <unistd.h>
	#include <stdlib.h>
	#include <stdio.h>
	#include <sys/types.h>
	#include <sys/wait.h>
	#include "get_next_line.h"

	typedef struct s_nb_exit nb_exit_t;

char **change_pwd(char **env);
char **my_str_to_word_array(char *str);
int my_strlen(char *str);
void my_put_char(char c);
void my_putstr(char *src);
void my_show_word_array(char **tab);
int find_path(char **env, int i);
char *find_env(char **env);
int nbr_path(char *str);
char **check_path(char *path);
char *my_strncat(char *d, char *s, int nb);
int check_n(char *buffer, int k);
void my_printf(char *str, ...);
int len_tab(char **str);
int verify_setenv(char **env, char *tab);
int find_line(char **save, char *tab);
char **find_setenv(char **save, char **tab);
void my_error(char *str);
char **modify_env(char **env, char **tab, nb_exit_t **buffer);
char **my_espace(char *str);
char *my_strdup(char *src);
char *find_home(char **env);
char *only_cd(char *buffer, char **env, char **tab);
int len_tab(char **str);
int verify_setenv(char **env, char *tab);
int find_line(char **save, char *tab);
int check_prog(char **part_path, char **tab, char **env, nb_exit_t **buffer);
int check_tab_bis(char **tab);
int check_v(char **tab);
void multi_error(char **tab, nb_exit_t **buffer);
int my_strncmp(char *s1, char *s2, int i);
int check_tab_bis(char **tab);
int check_v(char **tab);
int check_f(char **tab);
void test(int i);
int env_null(char **tab, char **env, nb_exit_t **buffer);
int check_prog_two(char **tab, char **env, nb_exit_t **buffer);
char **my_str_array(char *str, char c);
char **without_coma(char **tab, char *path);
int check_coma(char *str);
char *check_path_bis(char *str, int k);
char *epurstring(char *str);
char **lauch_simple_cmd(char **env, char *save, nb_exit_t **buffer);
int *pipe_with_wait(int nb_of_pipe);
int display_error_pipe(char **pipe, nb_exit_t **buffer);
int check_pipe_error(char **pipe, nb_exit_t **buffer);
int *pipe_with_wait(int nb_of_pipe);
int count_pipe(char **pipe);
int multi_pipe(int input, int i, char **save_instru);
void display_sg(int status, nb_exit_t **buffer);
int check_save(char *part_path, char **tab, char **env, nb_exit_t **buffer);
int permi_for_instru(char **tab, char **env, nb_exit_t **buffer);
nb_exit_t *init_nb_exit(void);
char **lauch_cmd(char *save, char **env, nb_exit_t **buffer);
void whoole_for_wait(int nb_of_pipe, nb_exit_t **buffer);
char **launch_pipe(char **env, char **save_instru, nb_exit_t **buffer);
char *my_parse_instru(char *instru, nb_exit_t **buffer, int *k);
int check_argv(char instru, char *argv);
char *new_cmd(char *instru, int i);
char *recup_name_file(char *instru);
int my_choice_redirection(char *instru, int i, nb_exit_t **buffer, int *k);
char *my_exit_for_redi(char *instru, int i, nb_exit_t **buffer, int *k);
char *my_parse_instru(char *instru, nb_exit_t **buffer, int *k);
int check_cd(char *tab);
int output_redi(char *instru, int i);
int input_redi(char *instru, int i, nb_exit_t **buffer, int *k);
void clean_ar(char **ar);
char **test1(char **env);
char **my_cutstr_to_ar(char *str, char s);
void prompt_way(void);
int my_arlen(char **array);
char **main_deux(char *save, char **env, nb_exit_t **buffer);

#endif
