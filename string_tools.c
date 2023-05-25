#include "shell.h"

/**
 * str_cat -a function that concatenates two strings
 * @dest: string to be concatenated
 * @src: original string
 * Return: Always 0
 */

char *str_cat(char *dest, char *src)
{
	int i, j = 0;

	for (i = 0; dest[i] != '\0'; i++)
	{
	}
	for (j = 0; src[j] != '\0'; j++)
	{
		dest[i] = src[j];
		i++;

	}
	dest[i] = '\0';
        return (dest);
}

/**
 * str_cmp - a function that does the comparison
 * @s1: string to be compared
 * @s2: string continuation
 * Return: many cases 0 , 1 , -1
 */

int str_cmp(char *s1, char *s2)
{
	int i = 0;
	int val;

	while (s1[i] != 0 && s2[i] != 0 && s1[i] == s2[i])
		i++;
	val = s1[i] - s2[i];
	return (val);
}

/**
 * str_len - a function that gets size of str
 * @s: string we want to know its length
 * Return: length
 */

int str_len(char *s)
{
	int i;

	for (i = 0; s[i] != 0; i++)
		;

	return (i);
}

/**
 *str_ncmp - a function that compares two strings.
 *@s1: first string
 *@s2: second string 
 *@n: how many characters
 * Return: the comparison (difference)
 */

size_t str_ncmp(char *s1, char *s2, size_t n)
{
	size_t i, j;

	for (j = 0; s1[j] != '\0' && j < n; j++)
	{
		i = s1[j] - s2[j];

		if (i != 0)
		{
			return (i);
		}
	}
	return (0);
}

/**
 * str_cpy - a function that  copies the string
 * @dest: string dest
 * @src: original src of copy
 * Return: char pointer
 */

char *str_cpy(char *dest, char *src)
{
	int i = 0;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	dest[i + 1] = 0;
	return (dest);
}
