#include "main.h"
/**
 * tokcount - Count the number of words
 * @s: String to be evaluated
 * @delim: String with delimiter
 *
 * Return: Count of words including NULL terminator
 */
int tokcount(char *s, const char *delim)
{
	char *s_cpy, *token;
	int count;

	if (s == NULL || delim == NULL)
	{
		return (0);
	}
	s_cpy = _strdup(s);
	count = 0;
	token = strtok(s_cpy, delim);
	while (token != NULL)
	{
		count++;
		token = strtok(NULL, delim);
	}
	count++;
	free(s_cpy);
	return (count);
}

/**
 * strtokenizer - Turn string into tokens
 * @s: String to be evaluated
 * @delim: String with delimiter
 *
 * Return: Array of pointers to word
 */
char **strtokenizer(char *s, const char *delim)
{
	char *token;
	char **arr;
	int index, word_count;

	if (s == NULL || delim == NULL)
	{
		return (NULL);
	}
	word_count = tokcount(s, delim);
	arr = malloc(sizeof(char *) * word_count);
	if (arr == NULL)
	{
		return (NULL);
	}
	index = 0;
	token = strtok(s, delim);
	while (token != NULL)
	{
		arr[index] = token;
		token = strtok(NULL, delim);
		index++;
	}
	arr[index] = NULL;
	return (arr);
}
/**
 * _strcmp - Comapres two strings
 * @s1: String one
 * @s2: String two
 *
 * Return: Difference between s1 and s2
 */
int _strcmp(char *s1, char *s2)
{
	int index;

	index = 0;
	while (s1[index] != '\0' || s2[index] != '\0')
	{
		if (s1[index] != s2[index])
		{
			return (s1[index] - s2[index]);
		}
		index++;
	}
	return (0);
}

/**
 * _strcpy - entry point
 * @dest: pointer to an arryay
 * @src: pointer to an array
 *
 * Description: copy a string
 * Return: dest
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return (dest);
}
/**
 * _strlen - entry point
 * @s: parameter for strings
 *
 * Description: returns the length of a string
 * Return: a value
 */
int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
		i++;
	return (i);
}
/**
 * _strncmp - Comapres two strings up to a certain character
 * @s1: String one
 * @s2: String two
 * @n: number of characters need to be compared
 *
 * Return: the number of the characters counted
 */
int _strncmp(char *s1, char *s2, int n)
{
	int i;
	int counter = 0;

	for (i = 0; i < n; i++)
	{
		if (s1[i] == s2[i])
			counter += 1;
	}
	return (counter);
}
/**
 * _strcat - Glue two strings together
 * @dest: String one
 * @src: String two
 *
 * Return: Pointer to dest
 */

char *_strcat(char *dest, char *src)
{
	int i;
	int j;

	for (i = 0; dest[i] != '\0'; i++)
		;
	for (j = 0; src[j] != '\0'; j++, i++)
	{
		dest[i] = src[j];
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * _strdup - Duplicate a string to newly allocated space
 * @str: String to be duplicated
 *
 * Return: Pointer to newly allocated space
 */
char *_strdup(char *str)
{
	int i;
	int j;
	int len = 0;
	char *a = NULL;

	if (str == NULL)
	{
		return (NULL);
	}
	for (j = 0; str[j] != '\0'; j++)
	{
		len++;
	}
	a = malloc(sizeof(char) * (len + 1));
	if (a == NULL)
	{
		return (NULL);
	}
	for (i = 0; str[i] != '\0'; i++)
	{
		a[i] = str[i];
	}
	a[i] = '\0';
	return (a);
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * _pathoma - Find the path of an arguement
 * @buff: Argument
 *
 * Return: Path to arguement
 */
char *_pathoma(char *buff)
{
	unsigned int i;
	int string_compare;
	char *second_path = NULL, *search_token = NULL;
	char *full_path = NULL, *alternatepath = NULL;
	int size;
	struct stat mystat;

	i = 0;
	while (environ[i] != NULL)
	{
		string_compare = _strncmp("PATH", environ[i], 4);
		if (string_compare == 4)
		{
			alternatepath = _strdup(environ[i]);
			strtok(alternatepath, "=");
			second_path = strtok(NULL, "=");
			if (second_path == NULL)
				return (NULL);
			search_token = strtok(second_path, ":");
			size = _strlen(buff) + _strlen(search_token) + 1;
			full_path = malloc(sizeof(char) * size);
			if (full_path == NULL)
				return (NULL);
			while ((search_token = strtok(NULL, ":")))
			{
				full_path[0] = '\0';
				_strcpy(full_path, search_token);
				_strcat(full_path, "/");
				_strcat(full_path, buff);
				if (stat(full_path, &mystat) == 0)
				{
					free(alternatepath);
					return (full_path);
				}
			}
		}
		i++;
	}
	free(alternatepath);
	return (buff);
}
/**
 * _fork - Create child and execute commands
 * @path: Absolute path
 * @args: Argument of tokens
 *
 * Return: EXIT_SUCCESS if successful and EXIT_FAILURE if fail
 */
int _fork(char *path, char **args)
{
	pid_t childPid;
	int status;
	int exit_status;

	childPid = fork();
	if (childPid == -1)
	{
		perror("Error:");
		return (EXIT_FAILURE);
	}
	else if (childPid == 0)
	{
		execve(path, args, NULL);
		exit(1);
	}
	else
	{
		wait(&status);
	}
	if (WIFEXITED(status))
		exit_status = WEXITSTATUS(status);
	return (exit_status);
}
/**
 * _bye - main entry, exit the program
 * @buff: pointer to the arguments
 * @exit_status: a variable integer
 *
 * Return: 0 on success or 1 on failure
 */

void _bye(char *buff, int exit_status)
{
	int i = exit_status;

	if (_strcmp(buff, "exit\n") == 0)
		exit(i);
}


/**
 * _env - entry point
 * Description: print the environment
 *
 */
void _env(void)
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		_putchar('\n');
	}
}
/**
 * main - Entry point for shell
 * @ac: Argument count
 * @av: Argument stirngs
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on fail
 */
int main(int ac __attribute__((unused)), char **av __attribute__((unused)))
{
	char *buff = NULL;
	size_t buff_size = 0;
	ssize_t chara;
	char **args = NULL;
	char *full_path = NULL;
	int i = 0, exit_status = 0;

	while (1)
	{
		if (isatty(STDIN_FILENO) == 1)
		{
			write(STDOUT_FILENO, "(prompt)$ ", 10);
		}
		chara = getline(&buff, &buff_size, stdin);
		while (*buff == ' ')
		{	i++;
			buff++;
		}
		if (chara == EOF)
		{
			if (isatty(STDIN_FILENO) == 1)
				_putchar('\n');
			return (EXIT_SUCCESS);
		}
		if (_strcmp(buff, "env\n") == 0)
		{
			_env();
			continue;
		}
		_bye(buff, exit_status);
		args = strtokenizer(buff, " \n");
		full_path = _pathoma(buff);
		exit_status = _fork(full_path, args);
	}
	buff = buff - i;
	return (exit_status);
}
