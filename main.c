#include "main.h"
/**
 * main - main program for simple shell
 * @ac: number of arguments
 * @argv: argument
 * @env: external environment variable
 * Return: 0 Always (success)
 */
int main(int ac, char **argv, char **env)
{
	char **cmd;
	pid_t pid_child;
	int status;
	(void)ac;

	while (1)
	{
		prints(PROMPT);
		cmd = read_split_cmd();

		if (cmd != NULL)
		{
			pid_child = fork();
			if (pid_child == -1)
			{
				perror("ERROR FORK");
				free_2Darray(cmd);
				exit(EXIT_FAILURE);
			}
			if (pid_child == 0)
			{
				execmd(cmd, argv[0], env);
				free_2Darray(cmd);
			}
			else
			{
				wait(&status);
			}
		}
	}
	exit(EXIT_SUCCESS);
}
