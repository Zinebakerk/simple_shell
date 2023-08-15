#include "shell.h"
/**
 * main - Simple Shell main function
 * @ac: Count of argumnents
 * @av: Arguments
 * @env: Environment
 * Return: 0 Always (success).
 */
int main(int ac, char **av, char **env)
{
	int status = 0;
	unsigned int idx = 0;
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
		idx++;
		command = split_line(line);
		if (!command)
			continue;
		if (is_builtin(command[0]))
		{
			handle_builtin(command, av, env, status);
			continue;
		}
		else
		{
			status = _execute(command, av, env, idx);
			if (status == 127)
			{
				if (!isatty(STDOUT_FILENO))
					exit(status);
				continue;
			}
		}
	}
}
