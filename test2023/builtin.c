
#include "main.h"
/**
 * exit_builtin - test
 * @cmd: test
 * @shell_name: test
 *
 * Return: test
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
 * env_builtin - test
 * @cmd: test
 * @shell_name: test
 *
 * Return: test
 */
void env_builtin(char **cmd, char *shell_name)
{
	int i = 0;

	(void)cmd;
	(void)shell_name;
	while (environ[i])
	{
		prints(environ[i]);
		prints("\n");
		i++;
	}
}
