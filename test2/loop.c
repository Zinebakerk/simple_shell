#include "main.h"

/**
 * check - function that takes the user input, then check for built-env
 * @env: pointer to pointer - environement
 * @name : shell_name
 * Return: void
 */

void check(char *env[], char *name)
{
	char *_line, char *factor, **cmd, char **di_r;

	while (1)
	{
		/* prompt message flagget out */
		_prompt();

		/* Ctrl + c handling */
		signal(SIGINT, handle_f);
		_line = _getline();
		cmd = split_line(_line);
		d_ir = dirTok(env);
		factor = checkPath(d_ir, cmd[0]);
		checkBuiltins(factor, cmd, name);

		/* perror flagged if not factor was found*/
		if (!factor)
			perror(factor);
	}
	buffers1(NULL, NULL);
	buffers2(NULL, NULL);
	buffers3(NULL, NULL);
	buffers4(NULL, NULL);
	buffers5(NULL);
}
