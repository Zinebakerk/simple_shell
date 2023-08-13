#include "shell.h"
/**
 * main - Main arguments functions
 * @ac: Count of argumnents
 * @av: Arguments
 * @env: Environment
 * Return: _exit = 0.
 */
int main(int ac, char **av, char **env)
{
	int counter = 0, status = 0;
	char *line = NULL, **commands = NULL;
	(void)ac;

	while (1)
	{
		line = _getline();
		if (line == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (0);
		}
		counter++;
		commands = get_command(line);
		if (!commands)
			continue;
		else
		{
			status = _fork(commands, av, env, counter);
			if (status == 200)
			{
				return (0);
			}
		}
	}
	return (status);
}
