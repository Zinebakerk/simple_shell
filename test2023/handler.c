#include "main.h"
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
	token = str_tok(path, ":");
	while (token)
	{
		cmd_full = malloc(str_len(cmd) + str_len(token) + 2);
		str_cpy(cmd_full, token);
		str_cat(cmd_full, "/");
		str_cat(cmd_full, cmd);
		if (stat(cmd_full, &st) == 0)
			return (cmd_full);
		free(cmd_full);
		token = str_tok(NULL, ":");
	}
	free(token);
	return (cmd);
}
/**
 * handle_builtin - test
 * @cmd: test
 * @shell_name: test
 *
 * Return: 1 if success or -1 if fails
 */
int handle_builtin(char **cmd, char *shell_name)
{
	int i;
	builtin builtins[] = {
		{"env", env_builtin},
		{"exit", exit_builtin},
		{NULL, NULL},
	};

	for (i = 0; builtins[i].cmd != NULL; i++)
	{
		if (str_cmp(cmd[0], builtins[i].cmd) == 0)
		{
			builtins[i].f(cmd, shell_name);
			return (1);
		}
	}
	return (-1);
}
