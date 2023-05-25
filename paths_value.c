#include "shell.h"

/**
 * get_path_values - function that do the separation by new strings.
 * @arg: user input
 * @env: external environement variable
 * Return: pointer to char
 */

int get_path_values(char *arg[], char **env)
{
	/* variables declaration */
	char *kento = NULL;
	char *path_route = NULL;
	char *path_bs = NULL;
	size_t value_rot, length;
	struct stat st;
	/* conditions tested*/

	if (stat(*arg, &st) == 0)
		return (-1);
	path_route = get_path_values(env);
	if (!path_route)
		return (-1);
	kento = strtok(path_route, ":"); 
	length = str_len(*arg); 
	while (kento)
	{
		value_rot = str_len(kento);
		path_bs = malloc(sizeof(char) * (value_rot + length + 2));
		if (!path_bs)
		{
			free(path_route);
			return (-1);
		}
		path_bs = str_cpy(path_bs, kento);
		str_cat(path_bs, "/");
		str_cat(path_bs, *arg);

		if (stat(path_bs, &st) == 0)
		{
			*arg = path_bs;
			free(path_route);
			return (0);
		}
		free(path_bs);
		kento = strtok(NULL, ":");
	}
	kento = '\0';
	free(path_route);
	return (-1);
}
