#include "main.h"
/**
 * main - Entry point
 * @argc: number of arguement
 * @argv: arguement
 * @envp: program’s environment
 * Return: 0 for sucess
 */
int main(int argc, char **argv, char **envp)
{
	if (argc == 1 || argv[1] == NULL)
		loop(envp);

	return (0);
}
