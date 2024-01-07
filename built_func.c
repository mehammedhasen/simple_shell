#include "shell.h"
/**
 * mycd - changes the current working directory of the shell
 * @get: array of arguments
 * Return: return 0 when fnesh
 */
int mycd(in_arg *get)
{
	char  *newwd, *oldwd, *change_cd, buf[1024];
	char *cwd;

	cwd = getcwd(buf, 1024);
	free(buf);
	if (!cwd)
		_puts("getcwd failurehere \n");

	change_cd  = get->argv[1];
	if (chdir(change_cd) != 0)
	{
	newwd = getcwd(buf, 1024);
	_puts(newwd);
	}
	else
	oldwd = cwd;
	_puts(oldwd);
	return (0);
}

/**
 * myexit- Exit the shell.
 * @get: Arguments.
 *
 * Return: exit.
 */
int myexit(in_arg *get)
{
	int status;

	if (get->argv[1] != NULL)
		status = _atoi(get->argv[1]);
	return (exit(status));
}
/**
 * myhelp - changes the current directory of the process
 * @get: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int myhelp(in_arg *get)
{
	char *ag_array;

	ag_array =  get->argv[1];

	_puts("please wait help Function not yet implemented \n");
	if (get->argv[1])
		_puts(ag_array);
	return (0);
}
/**
 * myhistory - displays the history list, one command by line, preceded
 *              with line numbers, starting at 0.
 * @get: Structure arguments.
 *  Return: Always 0
 */
int myhistory(in_arg *get)
{
	print_strg_in_alnode(get->history);
	return (0);
}
