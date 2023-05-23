#include "main.h"

int handle_builtin(char **cmd, char *shell_name)
{
	int i;
	struct builtin builtins[] =
       	{
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
 * get_env - function that get the value of the environement variable
 * @env-var: wanted environment variable
 *
 * Return: the value of the env variable if success
 * or NULL otherwise
 */
char *get_env(const char *env_var)
{
	int i = 0;
	char *key;
	extern char **environ;

	while (environ[i])
	{
		key = strtok(environ[i], "=");
		if (strcmp(env_var, key) == 0)
			return (strtok(NULL, "\n"));
		i++;
	}

	free(key);
	return (NULL);
}

/**
 * handle_path - function that handle the path of the command
 * @cmd: command to be handled
 * Return: if success, returns the full path
 * or the command otherwise
 */

char *handle_path(char *cmd)
{
	char *token, *path, *cmd_full;
	struct stat st;
 /* if the command is a valable path don't handle it */
	if (stat(cmd, &st) == 0)
	return (cmd);

	path = get_env("PATH");
	token = strtok(path, ":");
	while (token)
	{
			cmd_full = malloc(strlen(cmd) + strlen(token) + 2);
			strcpy(cmd_full, token);
			strcat(cmd_full, "/");
			strcat(cmd_full, cmd);
			if (stat(cmd_full, &st) == 0)
					return (cmd_full);
			free (cmd_full);
			token = strtok(NULL, ":");
	}
	free(token);
	return (cmd);
}

