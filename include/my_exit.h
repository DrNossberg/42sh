/*
** EPITECH PROJECT, 2018
** my_exit
** File description:
** .h
*/

#include "tokenizer.h"
#ifndef MY_EXIT
	#define MY_EXIT

	typedef struct s_alias {
		char *name;
		char *alias;
		struct s_alias *next;
	} alias_s;

	typedef struct s_nb_exit {
		int nb_exit;
		int *nb_wait;
		int nb_wait_choice;
		char *part_p;
		alias_s *alias;
		int n_of_alias;
	} nb_exit_t;

int number_arg(char **str);
token_t *tokeniser(char *str);
char **test1(char **env);
char *check_alias(nb_exit_t *buffer, char *save);
#endif
