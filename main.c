#include "shell.h"
#include <stdio.h>
/**
 * main - entry point
 *
 * Return: 0 on success, 1 on error
 */
int main(void)
{
	in_arg get[] = {ALL_ARGUMENT};
	int stat = 0, start = 0;
	

	listdown_all_env(get);
	read_hist_fle(get);
/*	signal(SIGINT,signal_handler);*/

	do {

		input_str(get);
		stat = find_builtin_func(get);
		if (stat == -1)
		{
			putchar('\n');
			execute_file(get);
		
		}

		clear_arg(get);
		start = 1;

	} while(start);

	return (0);
}
