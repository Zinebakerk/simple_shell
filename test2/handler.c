#include "main.h"

/**
 * handle_f - a function that handle the sign when it's delivered
 * @signal: received signal
 * Return: void
 */

void  handler(int sig)
{
	signal(sig, SIG_IGN);
	write(STDERR_FILENO, "\n", 1);
	_prompt();
	signal(SIGINT, handler);
}
