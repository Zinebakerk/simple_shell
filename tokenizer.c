#include "shell.h"

/**
 * toke_nize -a function that tokenizes a stirng
 * @ptr: input of the user
 * Return: a pointer to an array of pointers
 */

char **toke_nize(char *ptr)
{
	char **cmd = NULL;
	char *kento = NULL;
	size_t j = 0;
	int s = 0;

	if (ptr == NULL)
		return (NULL);

	for (j = 0; ptr[j]; i++)
	{
		if (ptr[j] == ' ')
			s++;
	}
	if ((s + 1) == str_len(ptr))
		return (NULL);
	cmd = malloc(sizeof(char *) * (s + 2));
	if (cmd == NULL)
		return (NULL);

	kento = strtok(ptr, " \n\t\r");

	for (j = 0; kento != NULL; j++)
	{
		cmd[j] = kento;
		kento = strtok(NULL, " \n\t\r");
	}
	cmd[j] = NULL;
	return (cmd);
}
