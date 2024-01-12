#include"shell.h"
/**
 * find_builtin_func - finds a builtin command
 * @get: the parameter & return info struct
 *
 * Return: -1 if func not found,
 */

int find_builtin_func(in_arg *get)
{
	int i;
	int chek_func = -1;


	buil_fun_tab buil_fun_ar[] = {
		{"exit", myexit},
		{"env", myenv},
		{"help", myhelp},
		{"setenv", mysetenv},
		{"unsetenv", myunsetenv},
		{"cd", mycd},
		{NULL, NULL}

	};

	for (i = 0; buil_fun_ar[i].type; i++)
	{
		
		if (_strcmp(get->argv[0], buil_fun_ar[i].type) == 0)
		{
			
			chek_func = buil_fun_ar[i].funcptr(get);
			break;
		}
		i++;
		
	}
	

	return(chek_func);

}

