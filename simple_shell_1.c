#include "main.h"
/**
 * main - Entry point
 *
 * Return: 0 Always (success)
 */
int main(void)
{
	char *buffer = NULL;
	size_t size_buff = 0;
	ssize_t r_bytes;

	while(true)
	{
		printf("%s", PROMPT);
		r_bytes = getline(&buffer, &size_buff, stdin);
		if(r_bytes != -1)
		{
			perror("EROOR GETLINE");
			exit(EXIT_FAILURE);
		}
		buffer[r_bytes - 1] = '\0';



	}



}
