#include "shell.h"
/**
 * 
 * 
*/
int _execute(char **arg, char **av, char **env, int counter)
{
	pid_t child;
	char *cmd;
	int status, i = 0;
	(void) counter;

	/*if (arg[0] == NULL)
	{
		free(arg), arg = NULL;
		return (1);
	}*/
	cmd = handle_path(arg[0]);
	child = fork();
	if (child == 0)
	{
		if (execve(cmd, arg, env) == -1)
		{
			perror(av[0]);
			for (i = 0; arg[i]; i++)
			{
				free(arg[i]), arg[i] = NULL;
			}
			free(cmd), cmd = NULL;
			free(arg), arg = NULL;
			exit(errno);
		}
	}
	else
	{
		wait(&status);
		for (i = 0; arg[i]; i++)
		{
			free(arg[i]), arg[i] = NULL;
		}
		free(cmd), cmd = NULL;
		free(arg), arg = NULL;
	}
	return (status);
}
