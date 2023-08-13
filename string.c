#include "shell.h"
/**
 * _strdup - a function that returns a pointer to a newly allocated space
 * in memory, which contains a copy of the string given as a parameter.
 * @str: a string given
 * Return: a pointer to a new string which is a duplicate of the
 * string str.Memory for the new string is obtained with malloc,
 * and can be freed with free.
 */
char *_strdup(char *str)
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
	for (i = 0; i < len; i++)
		ptr[i] = str[i];
	return (ptr);
}