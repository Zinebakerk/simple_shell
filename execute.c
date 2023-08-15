#include "shell.h"
int _execute(char **command, char **av, char **env, int idx)
{
	pid_t child;
	char *cmd;
	int status;

	cmd = _getpath(command[0]);
	if (!cmd)
	{
		print_error(av[0], idx, command[0]);
		free2Darray(command);
		return (127);
	}
	child = fork();
	if (child == 0)
	{
		execve(cmd, command, env);
	}
	else
	{
		waitpid(child, &status, 0);
		free2Darray(command);
		free(cmd), cmd = NULL;
	}
	return (WEXITSTATUS(status));
}
