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

#ifndef TOKEN
#define TOKEN

typedef enum e_token {
	SEPARATOR,
	CMD,
	OPTION,
	PIPE,
	DOUBLE_ASP,
	DOUBLE_PIPE,
	REDI_LEFT,
	D_REDI_LEFT,
	REDI_RIGHT,
	D_REDI_RIGHT
} multi_token_t;

typedef struct s_token {
	char *cmd;
	multi_token_t token;
	struct s_token *next;
} token_t;

typedef struct s_array_token {
	char choice;
	multi_token_t token;
} array_t;

#endif
