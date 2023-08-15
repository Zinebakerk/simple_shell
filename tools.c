#include "shell.h"
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
void print_error(char *name, unsigned int idx, char *cmd)
{
	char *num, mssg[] = ": not found\n";

	num = _itoa(idx);

	write(STDERR_FILENO, name, _strlen(name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, num, _strlen(num));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, _strlen(cmd));
	write(STDERR_FILENO, mssg, _strlen(mssg));
	free(num);
}
void reverse_string(char str[], int len)
{
	int start = 0;
	int end = len - 1;

	while (start < end)
	{
		char temp = str[start];

		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
}
char *_itoa(unsigned int n)
{
	char buffer[20];
	int i = 0;

	if (n == 0)
		buffer[i++] = '0';
	else
	{
		while (n > 0)
		{
			buffer[i++] = (n % 10) + '0';
			n /= 10;
		}
	}

	buffer[i] = '\0';
	reverse_string(buffer, i);

	return (_strdup(buffer));
}
