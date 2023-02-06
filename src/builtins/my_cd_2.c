/**
* @file my_cd_2.c
* @author Antoine Orion
* @author Julien Dubocage
*/

#include "my.h"

char *find_home(char **env)
{
	int i = 0;
	int j = 0;
	int k = 0;
	char *home = "HOME";

	while (env[i]) {
		j = 0;
		k = 0;
		while (j < 4) {
			if (env[i][j] == home[k])
				k++;
			if (k == 4)
				return (env[i] + 5);
			j++;
		}
		i++;
	}
	return (NULL);
}

char *only_cd(char *buffer, char **env, char **tab)
{
	char *save = buffer;

	getcwd(save, 255);
	save = my_strncat(save, "/", 1);
	buffer = find_home(env);
	if (access(buffer, F_OK) == -1) {
		my_error(tab[0]);
		my_error(": Not a directory.\n");
	}
	chdir(buffer);
	return (save);
}
