#include "main.h"

/**
 * get_line - get line from command
 * Return: buffer
 */
char *_getline(void)
{
	int exam;
	size_t bufsize = 0;
	char *buffer = NULL;

	/* user input*/

	exam = getline(&buffer, &bufsize, stdin);
	buffers3(NULL, buffer);

	if (exam == EOF)
	{
		buffers1(NULL, NULL);
		buffers2(NULL, NULL);
		buffers3(NULL, NULL);
		buffers4(NULL, NULL);
		buffers5(NULL);
		_exit(0);
	}
	return (buffer);
}

/**
 * prompt - function to print prompt
 * Return: void
 */

void _prompt(void)
{
	if (isatty(STDIN_FILENO))
	write(STDOUT_FILENO, "$ ", 2);
}


/**
 * split_line - function that splits the line given by the user
 * @line: the input command entered by the user
 * Return: token_Arr output
 */

char **split_line(char *input)
{
	int i = 1;
	char *d_buffer;
       	char *kento;
       	char *s_tok;
       	char **token_arr;


	d_buffer = str_dup(input);
	kento = strtok(input, DELIM);

	while (kento)
	{
		kento = strtok(NULL, DELIM);
		i++;
	}

	token_arr = malloc(4096);
	buffers4(token_arr, NULL);

	s_tok = strtok(d_buffer, DELIM);
	i = 0;
	while (s_tok)
	{
		token_arr[i] = s_tok;
		s_tok = strtok(NULL, DELIM);
		i++;
	}
	token_arr[i] = '\0';
	return (token_arr);
}
