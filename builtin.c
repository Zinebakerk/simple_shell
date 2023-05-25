#include "shell.h"
int cd_bultin(char **args);
int help_bultin(char **args);
int exit_shell(char **args);

char *builtin_str[] = {"cd", "help", "exit", "^D"};

int (*builtin_func[]) (char **) = {&cd_bultin, &help_bultin,
	&exit_shell, &ctrl_d_builtin};

/**
 * num_of_builtins - the number of builtins
 *
 * Return: num of builtins
 */

int num_of_builtins(void)
{
	return (sizeof(builtin_str) / sizeof(char *));
}
/**
 * cd_bultin - change directory
 * @args: usage
 *
 * Return: 1
 */
int cd_bultin(char **args)
{
	if (args[1] == NULL)
	{
		fprintf(stderr, "hsh: expected argument to \"cd\"\n");
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("hsh");
		}
	}
	return (1);
}

/**
 * help_bultin - print help page
 * @args: help usage
 *
 * Return: 1
 */
int help_bultin(char **args)
{
	int i;

	printf("This is the help page\n");
	(void)args;
	for (i = 0; i < num_of_builtins(); i++)
	{
		printf("  %s\n", builtin_str[i]);
	}

	return (1);
}

/**
 * exit_shell - exit the shell
 * @args: usage exit
 *
 * Return: 1
 */
int exit_shell(char **args)
{
	(void)args;
	free(args);
	return (200);
}

/**
 * ctrl_d_builtin - handle "^D" call
 * @args: "^D"
 *
 * Return: 0
 */
int ctrl_d_builtin(char **args)
{
	(void)args;
	free(args);
	return (200);
}

/**
 * _fork - a function that create a fork.
 * @av: shell name
 * @arg: The command
 * @env: environment variables
 * @np: Proces ID
 * @c: Checker add new test
 * @lineptr: input command line
 *
 * Return: 0 (success)
 */

int _fork(char **arg, char **av, char **env, char *lineptr, int np, int c)
{

	pid_t child;
	int status, i = 0;
	char *format = "%s: %d: %s: not found\n";

	if (arg[0] == NULL)
		return (1);
	for (i = 0; i < num_of_builtins(); i++)
	{
		if (str_cmp(arg[0], builtin_str[i]) == 0)
			return (builtin_func[i](arg));
	}
	child = fork();
	if (child == 0)
	{
		if (execve(arg[0], arg, env) == -1)
		{
			fprintf(stderr, format, av[0], np, arg[0]);
			if (!c)
				free(arg[0]);
			free(arg);
			free(lineptr);
			exit(errno);
		}
	}
	else
	{
		wait(&status);
		return (status);
	}
	return (0);
}
