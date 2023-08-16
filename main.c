#include "shell.h"
/**
 * main - Simple Shell main function
 * @ac: Count of argumnents
 * @av: Arguments
 * @env: Environment
 * Return: 0 Always (success).
 */
int main(int ac, char **av, char **env)
{
	int status = 0;
	char *line = NULL, **command = NULL;
	(void)ac;

	while (1)
	{
		line = _getline();
		if (line == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (status);
		}
		command = split_line(line);
		if (!command)
			continue;
		else
		{
			status = _execute(command, av, env);
			if (status == 127)
			{
				if (!isatty(STDIN_FILENO))
					exit(status);
				continue;
			}
		}
	}
}
/**
 * _getline -  GEts inputs
 * Return: The input.
 */
char *_getline(void)
{
	char *line = NULL;
	size_t len = 0;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, PROMPT, 2);

	if (getline(&line, &len, stdin) == -1)
	{
		free(line);
		return (NULL);
	}

	return (line);
}
int _execute(char **command, char **av, char **env)
{
	pid_t child;
	int status;

	child = fork();
	if (child == 0)
	{
		if (execve(command[0], command, env) == -1)
		{
			perror(av[0]);
			free2Darray(command);
			exit(127);
		}
	}
	else
	{
		waitpid(child, &status, 0);
		free2Darray(command);
	}
	return (WEXITSTATUS(status));
}
char **split_line(char *line)
{
	int i = 0, j = 0;
	char *token = NULL, *tmp = NULL,  delim[] = " \t\n";
	char **args = NULL;

	if (line == NULL)
		return (NULL);
	tmp = _strdup(line);
	token = strtok(tmp, delim);
	if (!token)
	{
		free(line), line = NULL;
		free(tmp), tmp = NULL;
		return (NULL);
	}
	while (token)
	{
		j++;
		token = strtok(NULL, delim);
	}
	args = malloc(sizeof(char *) * (j + 1));
	if (!args)
	{
		free(line), line = NULL;
		free(tmp), tmp = NULL;
		return (NULL);
	}
	free(tmp), tmp = NULL;
	tmp = _strdup(line);
	token = strtok(tmp, delim);
	while (token)
	{
		args[i++] = _strdup(token);
		token = strtok(NULL, delim);
	}
	args[i] = NULL;
	free(tmp), tmp = NULL;
	free(line), line = NULL;

	return (args);
}

/**
 * _strdup - a function that returns a pointer to a newly allocated space
 * in memory, which contains a copy of the string given as a parameter.
 * @str: a string given
 * Return: a pointer to a new string which is a duplicate of the
 * string str.Memory for the new string is obtained with malloc,
 * and can be freed with free.
 */
char *_strdup(const char *str)
{
	char *ptr;
	int i, len = 0;

	if (str == NULL)
		return (NULL);
	while (*str != '\0')
	{
		len++;
		str++;
	}
	str = str - len;
	ptr = malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
		return (NULL);
	for (i = 0; i <= len; i++)
		ptr[i] = str[i];
	return (ptr);
}
/**
  * _strcmp - a function that compares two strings
  * @s1: a pointer to the first string
  * @s2: a pointer to the second string
  * Return: integer
  */
int _strcmp(char *s1, char *s2)
{
	int cmp;

	cmp = (int)*s1 - (int)*s2;
	while (*s1)
	{
		if (*s1 != *s2)
			break;
		s1++;
		s2++;
		cmp = (int)*s1 - (int)*s2;
	}
	return (cmp);
}
/**
  * _strlen - a function that returns the length of a string
  * @s: a pointer to a string
  * Return: the lenght of the string
  */

int _strlen(char *s)
{
	int len = 0;

	while (s[len])
		len++;
	return (len);
}
/**
  * _strcat - a function that concatenates two strings
  * @src: a pointer to source string
  * @dest: a pointer to dest string
  * Return: the src string appending to the dest string
  */
char *_strcat(char *dest, char *src)
{
	char *p = dest;

	while (*p)
		p++;

	while (*src)
	{
		*p = *src;
		p++;
		src++;
	}
	*p = *src;
	return (dest);
}
/**
 *_strcpy - copies the string pointed to by src
 *@dest: A pointer to a char that will be changed
 *@src: A pointer to a char that will be changed
 *Return: dest
 */

char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void free2Darray(char **array)
{
	int i;

	if (!array)
		return;
	for (i = 0; array[i]; i++)
	{
		free(array[i]);
		array[i] = NULL;
	}

	free(array), array = NULL;
}