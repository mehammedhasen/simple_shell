#include "shell.h"
/**
 * signal_handler - handle the process interrept signal
 * @signo: the signal identifier
 *
 * Return: void
 */
void signal_handler()
{
	_putchar('\n');
	exit(1);
		
	
}
/**
 * error_print - prints an error msg
 * @strg: is the argv[0] on call
 * Return: is void
 */

void error_print(char *strg)
{
	int len = 0;
	len = _strlen(strg);
	write(2, strg, len);
}
