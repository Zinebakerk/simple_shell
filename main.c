#include "shell.h"
/**
 * main - Entry point
 * @ac: number of argumnents
 * @av: Arguments
 * @env: Environment
 * Return: 0 Always (success).
 */
int main(int ac, char **av, char **env)
{
	int pathValue = 0, status = 0, is_path = 0;
	char *line = NULL;
	char **commands = NULL;

	(void)ac;
	while (1)
	{
		errno = 0;
		line = get_cmd();
		if (line == NULL && errno == 0)
			return (0);
		if (line)
		{
			pathValue++;
			commands = toke_nize(line);
			if (!commands)
				free(line);
			if (!_strcmp(commands[0], "env"))
				_getenv(env);
			else
			{
				is_path = get_path_values(&commands[0], env);
				status = _fork(commands, av, env, line, pathValue, is_path);
					if (status == 200)
					{
						free(line);
						return (0);
					}
				if (is_path == 0)
					free(commands[0]);
			}
			free(commands);
		}
		else
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			exit(status);
		}
		free(line);
	}
	return (status);
}