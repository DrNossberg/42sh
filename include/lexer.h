/*
** EPITECH PROJECT, 2018
** lexer
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
