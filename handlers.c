#include "main.h"
/**
 * signal_handler - handle the process interrept signal
 * @sign: the signal identifier
 *
 * Return: void
 */
void signal_handler(int sign)
{
	if (sign == SIGINT)
	{
		prints("\n");
		prints(PROMPT);
	}
}
