#include "main.h"
/*
 *
 *
 */
void exit_builtin(char **cmd, char *shell_name)
{
	int i = 0, status = 0;

	if (cmd[1] != NULL)
	{
		while (cmd[1][i])
		{
			if (cmd[1][i] < '0' || cmd[1][i] > '9')
			{
				prints(shell_name + 2);
				prints(": exit: ");
				prints(cmd[1]);
				prints(": numeric argument required\n");
				free_2Darray(cmd);
				exit(2);
			}
			i++;
		}
		status = atoi(cmd[1]);
	}
	if (cmd[2] != NULL)
	{
		prints(shell_name + 2);
		prints(": exit: too many arguments\n");
		return;
	}
	free_2Darray(cmd);
	exit(status);
}
/**
 * handle_builtin -
 * @cmd:
 *
 * Return: 1 if success or -1 if fails
 */
int handle_builtin(char **cmd, char *shell_name)
{
	int i;
	struct builtin builtins[] = {
		{"env", env_builtin},
		{"exit", exit_builtin},
		{NULL, NULL},
	};

	for (i = 0; builtins[i].cmd != NULL; i++)
	{
		if (strcmp(cmd[0], builtins[i].cmd) == 0)
		{
			builtins[i].f(cmd, shell_name);
			return (1);
		}
	}
	return (-1);
}
/**
 *
 */
void env_builtin(char **cmd, char *shell_name)
{
	int i = 0;
	extern char **environ;

	(void)cmd;
	(void)shell_name;
	while (environ[i])
	{
		prints(environ[i]);
		prints("\n");
		i++;
	}
}
/**
 *
 *
 *
 *
 */
void free_2Darray(char **arr)
{
	int i = 0;

	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
