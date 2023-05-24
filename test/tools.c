#include "main.h"

/**
 * prints - a function that print a string to stdout
 * @str: the string to print
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
/**
 * split - test
 * @buffer: test
 *
 * Return: test
 */

char **split(char *buffer)
{
	char *dup, *token, **arr = NULL;
	int i, wc = 0;

	dup = str_dup(buffer);
	token = str_tok(dup, " \t\n");
	/* if there is no command */
	if (token == NULL)
		return (NULL);

	while (token != NULL)
	{
		wc++;
		token = str_tok(NULL, " \t\n");
	}
	arr = malloc(sizeof(char *) * (wc + 1));
	if (arr == NULL)
	{
		free(buffer);
		perror("EROOR MALLOC");
		exit(EXIT_FAILURE);
	}
	token = str_tok(buffer, " \t\n");
	for (i = 0; i < wc; i++)
	{
		arr[i] = token;
		token = str_tok(NULL, " \t\n");
	}

	arr[wc] = NULL;
	free(dup);
	return (arr);
}

/**
 * read_split_cmd - test
 *
 * Return: test
 */
char **read_split_cmd(void)
{
	char *buffer = NULL;

	buffer = read_cmd();
	return (split(buffer));
}

/**
* execmd - a function that execute a command
* @cmd: the command splitted
* @shell_name: the shell name
* @environ: environment variable
*
* Return: (void)
*/
void execmd(char **cmd, char *shell_name, char **environ)
{
	char *full_cmd;

	/* try handle path */
	full_cmd = handle_path(cmd[0]);
	if (execve(full_cmd, cmd, environ) == -1)
	{
		perror(shell_name);
		free_2Darray(cmd);
		exit(EXIT_FAILURE);
	}
}