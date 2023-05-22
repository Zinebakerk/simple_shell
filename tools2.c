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
		key = strtok(environ[i], "=");
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

char *handle_path(char *cmd)
{
	char *path = get_env("PATH");
	char *token;
	char *cmd_full;
	struct stat st;

	token = strtok(path, ":");
	while (token)
	{
	cmd_full = malloc(strlen(token) + strlen (cmd) + 2);
	strcpy(cmd_full, token);
	strcat(cmd_full, "/");
	strcat(cmd_full, cmd);
	if (stat(cmd_full, &st) == 0)
		return (cmd_full);
	free (cmd_full);
	token = strtok(NULL, ":");
	}
	return (cmd);
}
/*
char* strtok_custom(char* str, const char* delimiter) {
        char* current_token = NULL;
	char* token;
	if (str != NULL)
	{
	token = str;
	}
	else 
	{
	if (current_token == NULL)
	{
	return NULL;
	}
	}
	while (*current_token && strchr(delimiter, current_token)
	{
	current_token++;
	}
	if (*current_token == '\0')
	{
	}
	token = current_token;
*/
