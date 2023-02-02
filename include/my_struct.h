/*
** Cnam, en partenariat avec l'ITII Alsace, 2023
** Projet :
**    42sh
** Author :
**    Julien  DUBOCAGE
**    Antoine ORION
** File description:
** .h
*/

#ifndef _MY_STRUCT_
#define _MY_STRUCT_


typedef struct s_nb_exit nb_exit_t;

char **my_exit(char **env, char **tab, nb_exit_t **buffer);
char **modify_env(char **env, char **tab, nb_exit_t **buffer);
char **modify_unenv(char **env, char **tab, nb_exit_t **buffer);
char **my_cd(char **env, char **tab, nb_exit_t **buffer);
char **my_env(char **env, char **tab, nb_exit_t **buffer);
char **my_alias(char **env, char **tab, nb_exit_t **buffer);
char **my_echo(char **env, char **str, nb_exit_t **buffer);
char **my_cwd(char **env, char **str, nb_exit_t **buffer);

typedef struct          s_flags {
	char		*lt;
	char		**(*sf)(char **env, char **tab, nb_exit_t **buffer);
}			flags_t;

flags_t bultin[] = {
	{"setenv", modify_env},
	{"unsetenv", modify_unenv},
	{"cd", my_cd},
	{"env", my_env},
	{"exit", my_exit},
	{"echo", my_echo},
	{"alias", my_alias},
	{"cwd", my_cwd},
	{NULL, NULL}
};

#endif
