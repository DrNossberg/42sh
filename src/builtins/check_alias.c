/**
* @file check_alias.c
* @author Antoine Orion
* @author Julien Dubocage
*/

#include <memory.h>
#include "my_exit.h"

/**
 * @fn char *change_alias(char *save, alias_s *tmp, size_t a)
 * Replaces the save string with the string associated with the alias
 * @brief gets the real command from an alias
 * @param save alias to replace
 * @param tmp Pointer to the alias structure
 * @param a length of the alias
 * 
*/
static char *change_alias(char *save, alias_s *tmp, size_t a)
{
	char *alias = strdup(tmp->alias);

	if (strlen(save) > a) {
		for (size_t i = 0; i < a; i++, save++);
		return (strcat(alias, save));
	}
	return (alias);
}

/**
 * @fn char *check_alias(nb_exit_t *buffer, char *save)
 * 
 * @brief checks if the command is an alias
 * @param buffer Pointer to a structure that holds info about the current shell's state
 * @param save alias to check
 * @return the real command if the command is an alias, otherwise the save string
*/
char *check_alias(nb_exit_t *buffer, char *save)
{
	alias_s *tmp = buffer->alias;
	size_t a;

	for (int i = 0; i < buffer->n_of_alias; i++) {
		a = strlen(tmp->name);
		if (!strncmp(save, tmp->name, a))
			return (change_alias(save, tmp, a));
		tmp = tmp->next;
	}
	return (save);
}
