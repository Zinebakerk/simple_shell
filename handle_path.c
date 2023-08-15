#include "shell.h"
/**
 * 
 * 
*/
list_dir *build_dir_list(void)
{
	list_dir *head = NULL;
	char *path_env, *token;

	path_env = _getenv("PATH");
	if (!path_env)
		return (NULL);
	token = strtok(path_env, ":");
	while (token)
	{
		add_node_end(&head, token);
		token = strtok(NULL, ":");
	}
	free(path_env);
	return (head);
}
/**
 * 
 * 
*/
char *_getpath(char *command)
{
	list_dir *ld, *tmp;
	char *full_cmd, *check;
	struct stat st;
	
	check = _getenv("PATH1");
	if (stat(command, &st) == 0)
	{
		if (check)
		{
			free(check);
			return (NULL);
		}
		return (_strdup(command));
	}
	ld = build_dir_list();
	tmp = ld;
	while (tmp)
	{
		full_cmd = malloc(_strlen(tmp->dir) + _strlen(command) + 2);
		if (!full_cmd)
		{
			free_list_dir(ld);
			return (NULL);
		}
		_strcpy(full_cmd, tmp->dir);
		_strcat(full_cmd, "/");
		_strcat(full_cmd, command);
		if (stat(full_cmd, &st) == 0)
		{
			free_list_dir(ld);
			return (full_cmd);
		}
		free(full_cmd);
		tmp = tmp->next;
	}
	free_list_dir(ld);
	return (NULL);

}
