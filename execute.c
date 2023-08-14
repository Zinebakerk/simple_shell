#include "shell.h"
/**
 * 
 * 
*/
int _execute(char **arg, char **av, char **env, unsigned int idx)
{
	pid_t child;
	char *cmd;
	int status;

	cmd = handle_path(arg[0]);
	if (!cmd)
	{
		print_error(av[0], idx, arg[0]);
		free2Darray(arg);
		return (-1);
	}
	child = fork();
	if (child == 0)
	{
		execve(cmd, arg, env);	
	}
	else
	{
		wait(&status);
		free2Darray(arg);
		free(cmd), cmd = NULL;
	}
	return (status);
}

