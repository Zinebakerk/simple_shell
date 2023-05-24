#include "main.h"
/**
* execmd - a function that execute a command
* @cmd: the command splitted
* @shell_name: the shell name
* @environ: environment variable
*
* Return: (void)
*/
void execmd(char **cmd, char *shell_name, char **env)
{
	if (execve(cmd[0], cmd, env) == -1)
	{
		perror(shell_name);
		free_2Darray(cmd);
		exit(EXIT_FAILURE);
	}
}
