#include "shell.h"
/**
 * clear_info_var - initializes info_t struct
 * @get: struct address
 */
void clear_arg(in_arg *get)
{	
	int i = 0;
	get->str_ptr = NULL;
	get->argc = 0;
	while(get->argv[i] != 0)
	{
		free(get->argv[i]);
		i++;
	}
	get->argv = NULL;
}

