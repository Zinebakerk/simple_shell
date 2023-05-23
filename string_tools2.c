#include "main.h"

/**
 * str_spn - function that searches a string for a set of bytes
 * @str: char string array
 * @delimiters: char array to check bytes with
 * Return: Number of butes in the initial segment of "s"
 */
unsigned int strc_spn(char *str, const char *delimiters)
{
	size_t length = 0;

     	while (*str != '\0')
       	{
		 const char *delimiter = delimiters;
	 	while (*delimiter != '\0')
	 	{
			if (*str == *delimiter)
			{	
	       			return length;
			}
			delimiter++;
	 	}
		str++;
       		length++;
	}
	return length;
}

/**
 * str_tok - function that splits a string based on delimiters
 * @str: string input
 * @delimiter: char input
 * Returns the current token
 */

char *str_tok(char *str, const char *delimiter)
{	
	static char *token = NULL;
	char *token_end = NULL;
	if (str == NULL)
	{
		str = token;
	}
	/* skip other delimeters */
	str += strc_spn(str, delimiter);

	if (*str == '\0')
	{
		token = NULL;
		return (NULL);
	}

	token_end = str + strc_spn(str, delimiter);

	if (*token_end != '\0')
	{
		*token_end = '\0';
		token = token_end + 1;
	}
	else
	{
		token = NULL;
	}
	return (str);
	}

