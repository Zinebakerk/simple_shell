#include "shell.h"
/**
 * _getenv - print env to stdout
 * @env: enviroment variables
 *
 * Return: void
 */
void _getenv(char **env)
{
	size_t len = 0;

	while (env[len])
	{
		write(STDOUT_FILENO, env[len], _strlen(env[len]));
		write(STDOUT_FILENO, "\n", 1);
		len++;
	}
}
