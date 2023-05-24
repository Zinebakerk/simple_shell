#include "main.h"
/**
* execmd - a function that execute a command
* @cmd: the command splitted
* @shell_name: the shell name
* @environ: environment variable
*
* Return: (void)
*/
void execmd(char **cmd, char *shell_name, char **environ)
{
	if (execve(cmd[0], cmd, environ) == -1)
	{
		perror(shell_name);
		exit(EXIT_FAILURE);
	}
}
