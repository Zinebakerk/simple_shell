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
void handle_builtin(char **command, char **av, char **env, int st, int idx)
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
			B[i].f(command, av, env, st, idx);
			break;
		}
	}
}
void exit_shell(char **command, char **av, char **env, int status, int idx)
{
	int exit_status = status;
	char *index, mssg[] = ": exit: Illegal number: ";
	(void) env;

	if (command[1])
	{
		if (!is_positive_number(command[1]))
		{
			index = _itoa(idx);
			write(STDERR_FILENO, av[0], _strlen(av[0]));
			write(STDERR_FILENO, ": ", 2);
			write(STDERR_FILENO, index, _strlen(index));
			write(STDERR_FILENO, mssg, _strlen(mssg));
			write(STDERR_FILENO, command[1], _strlen(command[1]));
			write(STDERR_FILENO, "\n", 1);
			free(index);
			free2Darray(command);
			if (!isatty(STDIN_FILENO))
				exit(2);

			return;
		}
		else
			exit_status = _atoi(command[1]);
	}
	free2Darray(command);
	exit(exit_status);
}
void print_env(char **command, char **av, char **env, int status, int idx)
{
	int i;
	(void) command;
	(void) av;
	(void) status;
	(void) idx;

	for (i = 0; env[i]; i++)
	{
		write(STDOUT_FILENO, env[i], _strlen(env[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
	free2Darray(command);
}
