#include "main.h"

/**
 * handle_f - a function that handle the sign when it's delivered
 * @signal: received signal
 * Return: void
 */

void  handle_f(int signal)
{
	signal(sig, SIG_IGN);
	write(STDERR_FILENO, "\n", 1);
	prompt();
	signal(SIGINT, handle_f);
}
