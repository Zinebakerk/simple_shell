#include "main.h"

/**
 * exit_sh - function that quits from shell
 * @command: command input
 * Return: if success 0 , failed 1
 */
int exit_sh(char **command)
{
	if (*command)
	{
		buffers1(NULL, NULL);
		buffers2(NULL, NULL);
		buffers3(NULL, NULL);
		buffers4(NULL, NULL);
		buffers5(NULL);
		exit(2);
	}
	return (0);
}

/**
 * cd - function that changes the directory 
 * @command: command input
 * Return: if success 0 , failed 1
 */
int cd(char **command)
{
	chdir(command[1]);
	return (0);
}

/**
 * printenv - function that  prints the environ
 * @command: pointer to command
 * Return: 0 for success
 */
int printenv(char **command)
{
	int i;

	if (*command)
	{
		i = 0;
		while (environ[i])
		{
			write(1, environ[i], _strlen(environ[i]));
			write(1, "\n", 1);
			i++;
		}
	}
	return (0);
}

/**
 * checkBuiltins - function that check for builtins
 * @combine:directory
 * @command:input command line
 * Return: process from directory
 */
int checkBuiltins(char *combine, char **command, char *shell_name)
{
	int i;
	char *array[] = {"exit", "cd", "env", NULL};

	typedef int (*Builtins)(char **);
	Builtins functions[] = {&exit_sh, &cd, &printenv};

	i = 0;
	while (array[i] != NULL)
	{
		if (_strcmp(array[i], command[0]) == 0)
			return (functions[i](command));
		i++;
	}
	return (execute(combine, command, shell_name));
}
