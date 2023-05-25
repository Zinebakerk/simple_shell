#include "shell.h"
int cd_builtin(char **args);
int help_builtin(char **args);
int exit_builtin(char **args);
int ctrld_biltin(char **args);

char *builtin_str[] = {"cd", "help", "exit", "^D"};

int (*builtin_func[]) (char **) = {&lsh_cd, &lsh_help, &lsh_exit, &lsh_ctrld};

/**
 * num_of_builtins - size
 *
 * Return: size
 */
int num_of_builtins(void)
{
	return (sizeof(builtin_str) / sizeof(char *));
}

/**
 * cd_builtin - builtin to change dirs
 * @args: cd command (cd <directory>)
 *
 * Return: 1 on success
 */
int cd_builtin(char **args)
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
 * help_builtin - a function that print the help page for the shell
 * @args: help command
 *
 * Return: 1 Always
 */
int help_bultin(char **args)
{
	int i;

	printf("help page\n");
	printf("Mouad && Zineb\n");
	(void)args;
	for (i = 0; i < num_of_builtins(); i++)
	{
		printf("  %s\n", builtin_str[i]);
	}

	return (1);
}

/**
 * ecit_builtin - a function that exits the shell
 * @args: exit usage
 *
 * Return: 0 Always
 */
int exit_builtin(char **args)
{
	(void)args;
	free(args);
	return (200);
}

/**
 * ctrld_builtin - builtin to handle "^D" call
 * @args: usage
 *
 * Return: Always 0
 */
int ctrld_builtin(char **args)
{
	(void)args;
	free(args);
	return (200);
}

/**
 * _fork - create a fork.
 * @c: Checker add new test
 * @np: Process ID
 * @arg: the Command
 * @av: shell name
 * @env: environment variables
 * @lineptr: buffer of input command
 *
 * Return: in success 0
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
		if (_strcmp(arg[0], builtin_str[i]) == 0)
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
