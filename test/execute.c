#include "main.h"

/**
 * execmd - a function that execute a command
 * @cmd: the command splitted
 * @shell_name: the shell name
 * @environ: external environement variable
 * Return: (void)
 */
void execmd(char **cmd, char *shell_name, char **environ)
{
	char *full_cmd;

	 /* try handle path */
	full_cmd = handle_path(cmd[0]);
	if (execve(full_cmd, cmd, environ) == -1)
	{
		perror(shell_name);
		free_2Darray(cmd);
		exit(EXIT_FAILURE);
	}
}
