#include "main.h"

/**
 * prints - a function that print a string to stdout
 * str: the string to print
 *
 * Return: (void)
 */
void prints(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		write(STDOUT_FILENO, &str[i], 1);
		i++;
	}
}

/**
* read_cmd - a function that reads command from the stdin and
* split it to an array of each word of the string
*
* Return: (void)
*/

char *read_cmd(void)
{
	size_t size = 0;
	ssize_t r_bytes;
	char *buffer = NULL;

	r_bytes = getline(&buffer, &size, stdin);
	if (r_bytes == -1)
	{
		exit(EXIT_FAILURE);
	}
	buffer[r_bytes - 1] = '\0';
	return (buffer);
}


char **split(char *buffer)
{
	char *dup, *token, **arr = NULL;
	int wc = 0;

	dup = str_dup(buffer);
	token = strtok(dup, " \t\n");
	/* if there is no command */
	if (token == NULL)
		return (NULL);

	while (token != NULL)
	{
		wc++;
		arr = realloc(arr, sizeof(char *) * (wc + 1));
		if (arr == NULL)
		{
			free(dup);
			perror("EROOR REALLOC");
			exit(EXIT_FAILURE);
		}
		arr[wc - 1] = str_dup(token);
		token = strtok(NULL, " \t\n");
	}
	arr[wc] = NULL;
	free(dup);
	return (arr);
}


char **read_split_cmd(void)
{
	char *buffer = NULL;

	buffer = read_cmd();
	return (split(buffer));
}

/**
* execmd - a function that execute a command
* @cmd: an array of strings of commands
* @shell_name: the shell name
*
* Return: (void)
*/
void execmd(char **cmd, char *shell_name, char **env)
{
	char *full_cmd;

	full_cmd = handle_path(cmd[0]);
	if (execve(full_cmd, cmd, env) == -1)
	{
	perror(shell_name);
	exit(EXIT_FAILURE);
	}
}
