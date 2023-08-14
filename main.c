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
	int counter = 0;
	char *line = NULL, **command = NULL;
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
		command = split_line(line);
		if (!command)
			continue;
		else
		{
			_execute(command, av, env, counter);
		}
	}
}
