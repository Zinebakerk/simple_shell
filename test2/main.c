#include "main.h"

/**
 * main - function that execute the code 
 * @argc: arguments count
 * @argv: arguments variables 
 * @envp: external environemet variable
 * Return: if code ran successfuly returns 0 , otherwise 1 if fails
 */

int main(int argc, char *argv[], char *envp[])
{
	if (argc == 1 || argv[1] == NULL)
		check(envp, argv[0]);

	return (0);
}
