#include "main.h"
/**
 * signal_handler - handle the process interrept signal
 * @signa: the signal identifier
 *
 * Return: void
 */
void signal_handler(int signa)
{
	if (signa == SIGINT)
	{
		prints("\n");
		prints(PROMPT);
	}
}
