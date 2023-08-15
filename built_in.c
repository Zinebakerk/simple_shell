#include "shell.h"
int is_builtin(char *command)
{
	int i;
	char *builtins[] = {"exit", "env", "cd", NULL};

	for (i = 0; builtins[i]; i++)
	{
		if (_strcmp(command, builtins[i]) == 0)
			return (1);
	}
	return (0);
}
void handle_builtin(char **command, char **av, char **env, int status)
{
	int i;
	builtins B[] = {
		{"exit", exit_shell},
		{"env", print_env},
		{NULL, NULL}
	};

	for (i = 0; B[i].builtin; i++)
	{
		if (_strcmp(B[i].builtin, command[0]) == 0)
		{
			B[i].f(command, av, env, status);
			break;
		}
	}
}
void exit_shell(char **command, char **av, char **env, int status)
{
	int exit_status = status;
	(void) av;
	(void) env;

	if (command[1])
		exit_status = atoi(command[1]);
	free2Darray(command);
	exit(exit_status);
}
void print_env(char **command, char **av, char **env, int status)
{
	int i;
	(void) command;
	(void) av;
	(void) status;

	for (i = 0; env[i]; i++)
	{
		write(STDOUT_FILENO, env[i], _strlen(env[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
	free2Darray(command);
}
