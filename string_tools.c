#include "main.h"

/**
 * str_len - function that returns the length of a string
 * @str: the given string input
 *Return: string length
 */

unsigned int str_len(char *str)
{
	unsigned int i;

	for (i = 0; str[i] != '\0'; i++)
		;
	return (i);
}

/**
 * str_cpy - function that copies src to dest
 * @dest: input char
 * @src: the copied char 
 * Return: the copied char 
 */

char *str_cpy(char *dest, const char *src)
{
	int len;

	for (len = 0; src[len] != '\0'; ++len)
	{
		dest[len] = src[len];
	}
	dest[len] = '\0';
	return (dest);
}

/**
 * str_cat - appends the src string to the dest string
 * @dest: input string
 * @src: input const string
 * Return: result
 */

char *str_cat(char *dest, const char *src)
{
	char *result = dest;

	while (*dest != '\0')
		dest++;

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';

	return (result);
}

/**
 * str_cmp - function that compares two strings
 * @s1: input string
 * @s2: input string
 * Return : return an integer showing the result of the comp , 0 if s1 and s2 were equal
 * negative value if s1 is less than s2
 * positive if s1 is greater than s2
 */

int str_cmp(const char *s1, const char *s2)
{
	int i;
	int res = 0;

	for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
		{
			res = s1[i] - s2[i];
			break;
		}
	}

	return (res);
}

/**
 * str_dup - function that return a pointer to newly allocated space in memo
 * this pointer have a copy of the string in the paramater
 * @str: string input
 * Return: pointer
 */

char *str_dup(const char *str)
{
	int i, len = 0;
	char *result;

	if (str == NULL)
		return (NULL);

	while (str[len] != '\0')
		len++;

	result = (char *)malloc((len + 1) * sizeof(char));

	if (result == NULL)
		return (NULL);

	for (i = 0; i <= len; i++)
		result[i] = str[i];

	return (result);
}
