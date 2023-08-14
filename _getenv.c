#include "shell.h"
/**
 * 
 * 
*/
char *_getenv(char *variable)
{
	char *key, *tmp, *env;
	int i;

	for (i = 0; environ[i]; i++)
	{
		tmp = _strdup(environ[i]);
		key = strtok(tmp, "=");
		if (_strcmp(key, variable) == 0)
		{
			env = _strdup(strtok(NULL, "\n"));
			free(tmp);
			return (env);
		}
		free(tmp);
	}

	return (NULL);
}