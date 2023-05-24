 #include "main.h"
/**
 * get_env - function that get the value of the environement variable
 * @env_var: wanted environment variable
 *
 * Return: the value of the env variable if success
 * or NULL otherwise
 */
char *get_env(const char *env_var)
{
	char *key;
	int i = 0;

	while (environ[i])
	{
		key = str_tok(environ[i], "=");
		if (str_cmp(env_var, key) == 0)
			return (str_tok(NULL, "\n"));
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
