#include "main.h"

/*
 * get_env - function that avalaibility of the path
 * @env-var : wanted evironement variable
 * return : Success , if the variable was found , NULL if it wasn't
 */


char *get_env(const char *env_var)
{
	int i = 0;
	char *key;
	extern char **environ;

	while (environ[i])
	{
		key = str_tok(environ[i], "=");
		if (str_cmp(env_var, key) == 0)
			return (str_tok(NULL, "\n"));
		i++;
	}
	return (NULL);
}

/**
 * get_env_cmd - function that checks the env of the command
 * @cmd : command to be checked
 * return : if success  , returns the output , NULL  if it wasn't
 */

char *handle_path(char *cmd)
{
	char *path = get_env("PATH");
	char *token;
	char *cmd_full;
	struct stat st;

	token = str_tok(path, ":");
	while (token)
	{
	cmd_full = malloc(str_len(token) + str_len (cmd) + 2);
	str_cpy(cmd_full, token);
	str_cat(cmd_full, "/");
	str_cat(cmd_full, cmd);
	if (stat(cmd_full, &st) == 0)
		return (cmd_full);
	free (cmd_full);
	token = str_tok(NULL, ":");
	}
	return (cmd);
}
