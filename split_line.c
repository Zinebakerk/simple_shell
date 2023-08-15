#include "shell.h"
char **split_line(char *line)
{
	int i = 0, j = 0;
	char *token = NULL, *tmp = NULL,  delim[] = " \t\n";
	char **args = NULL;

	if (line == NULL)
		return (NULL);
	tmp = _strdup(line);
	token = strtok(tmp, delim);
	if (!token)
	{
		free(line), line = NULL;
		free(tmp), tmp = NULL;
		return (NULL);
	}
	while (token)
	{
		j++;
		token = strtok(NULL, delim);
	}
	args = malloc(sizeof(char *) * (j + 1));
	if (!args)
	{
		free(line), line = NULL;
		free(tmp), tmp = NULL;
		return (NULL);
	}
	free(tmp), tmp = NULL;
	tmp = _strdup(line);
	token = strtok(tmp, delim);
	while (token)
	{
		args[i++] = _strdup(token);
		token = strtok(NULL, delim);
	}
	args[i] = NULL;
	free(tmp), tmp = NULL;
	free(line), line = NULL;

	return (args);
}
