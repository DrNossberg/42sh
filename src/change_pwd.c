/**
* @file change_pwd.c
* @author Antoine Orion
* @author Julien Dubocage
*/
#include "../include/my.h"
#include "../include/my_exit.h"

/**
 * @fn char **change_pwd(char **env)
 * @brief Changes the value of the PWD (present working directory) variable in the environment
 * @param env Array of environment variables used by the shell
 * @return The modified environment
*/
char **change_pwd(char **env)
{
	int i = find_line(env, "PWD");
	char *str = NULL;
	char *pwd = strdup("PWD=");
	char *src = NULL;

	str = getcwd(str, 255);
	if (str == NULL)
		return (env);
	src = my_strncat(pwd, str, (int)(strlen(str)));
	env[i] = strdup(src);
	return (env);
}