 #include "main.h"
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
