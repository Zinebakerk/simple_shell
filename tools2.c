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

	while (env[i])
	{
		key = strtok(env[i], "=");
		if (strcmp(env_var, key) == 0)
			return (strtok(NULL, "\n"));
		i++;
	}
	return (NULL);
}

/**
 * get_env_cmd - function that checks the env of the command
 * @cmd : command to be checked
 * return : if success  , returns the output , NULL  if it wasn't
 */

char *get_env_cmd(char *cmd)
{
	char *path = get_env("PATH");
	char *token ;
	char *cmd_full;
	struct stat check;

	token = strtok(path, ":");
	while (token)
	{
	cmd_full = malloc(strlen(token) + strlen (command) + 2);
	strcpy(cmd_full, token);
	strcat(cmd_full, "/");
	strcat(cmd_full, command);
	if (str(cmd_full, &check) == 0)
		return (cmd_full);
	free (cmd_full);
	token = strtok(NULL, ":");
	}
	return (NULL);
}

