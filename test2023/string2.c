#include "main.h"

/**
 * str_chr - function that searches a string for a set of bytes
 * @str: char string array
 * @c: char array to check bytes with
 * Return: Number of butes in the initial segment of "s"
 */

char *str_chr(const char *str, int c)
{
	while (*str)
	{
		if (*str == (char)c)
		{
			return ((char *)str);
		}
		str++;
	}

	return (NULL);
}

/**
 * str_tok - function that splits a string based on delimiters
 * @str: string input
 * @delimiter: char input
 * Return: the current token
 */
char *str_tok(char *str, const char *delimiter)
{
	static char *token;
	char *token_end = NULL;

	if (str != NULL)
		token = str;

	else
	{
		if (token == NULL)
			return (NULL);
	}
	while (*token && str_chr(delimiter, *token) != NULL)
		token++;

	if (*token == '\0')
		return (NULL);

	token_end = token;

	while (*token && str_chr(delimiter, *token) == NULL)
		token++;

	if (*token != '\0')
	{
		*token = '\0';
		token++;

	}
	return (token_end);
}
