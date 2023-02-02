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

#ifndef LEXER
# define LEXER

typedef struct s_parser {
	char *cmd;
	multi_token_t token;
//	struct s_parser *parents;
	struct s_parser *right;
	struct s_parser *left;
} parser_tree_t;

parser_tree_t *parsing_token(token_t *token);

#endif
