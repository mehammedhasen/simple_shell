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
		{"history", myhistory},
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

/**
 * execute_file - Execute a command with arguments.
 * @get: An array of strings containing the command and its arguments.
 *
 * Return: The exit status of the executed command.
 */
void execute_file(in_arg *get)
{
	pid_t child;
	char **envir;
	char *flpath = NULL;

	if (get->argv == NULL || get->argv[0])
		return;
	flpath = malloc(sizeof(char) * PATH_MAX);
	if (!flpath)
		error_print("path holder is null");
	
	flpath = find_file_path(get, _getenv(get, "PATH="), get->argv[0]);
	get->file_path = flpath;
	envir = alloc_environ(get);
	child = fork();
	if (child < 0)
	{
		error_print("fork is cannot run");
	
	}

	if (child == 0)
	{

		if (execve(flpath, get->argv, envir) == -1)
		{
			error_print(" file is unknow cannot excute");
			free(flpath);
			envir = NULL;
			clear_arg(get);
			putchar('\n');
			input_str(get);
		
		}
	exit(2);
	}

	waitpid(child, &(get->status), 0);
	if (WIFSIGNALED(get->status))
		error_print("signal inter-rupt");
	else if(WEXITSTATUS(get->status))
		_puts("pls exit normaly");

	return ;


}
