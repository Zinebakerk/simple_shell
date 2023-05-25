#include "shell.h"

/**
 * get_path - function that gets the variable path
 * @env: extern environement variable
 *
 * Return: path value
 */

char *get_path(char **env)
{
	size_t ind = 0;
	size_t s = 0;
	ssize_t counter = 5;
	char *v_path = NULL;

	for (ind = 0; str_ncmp(env[ind], "PATH=", 5); ind++)
		;
	if (env[ind] == NULL)
		return (NULL);

	for (counter = 5; env[ind][s]; s++, counter++)
		;
	v_path = malloc(sizeof(char) * (counter + 1));

	if (v_path == NULL)
		return (NULL);

	for (s = 5, counter = 0; env[ind][s]; s++, counter++)
		v_path[counter] = env[ind][s];

	v_path[counter] = '\0';
	return (v_path);
}
