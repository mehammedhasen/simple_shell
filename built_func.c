#include "shell.h"
/**
 * mycd - changes the current working directory of the shell
 * @get: array of arguments
 */
int mycd(in_arg *get)
{
	char  *newdir, *cwd, buf[1024];
	int change_cd;

	cwd = getcwd(buf, 1024);
	if (!cwd)
		_puts("getcwd fail to show PWD rehere \n");

	if (!get->argv[1])
	{
		newdir = _getenv(get, "HOME=");
		if (!newdir)
			change_cd = chdir((newdir = _getenv(get, "PWD=")) ? newdir : "/"); /* TODO: what should this be? */
		else
			change_cd = chdir(newdir);
	}
	else if (_strcmp(get->argv[1], "-") == 0)
	{
		if (!_getenv(get, "OLDPWD="))
		{
			_puts(cwd);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(get, "OLDPWD=")), _putchar('\n');
		change_cd = chdir((newdir = _getenv(get, "OLDPWD=")) ? newdir : "/");
	}
	else
		change_cd = chdir(get->argv[1]);
	if (change_cd == -1)
	{
		error_print("cd cannot change directory  ");
		_puts(get->argv[1]), _putchar('\n');
	}
	else
	{
		_setenv(get, "OLDPWD", _getenv(get, "PWD="));
		_setenv(get, "PWD", getcwd(buf, 1024));
	}
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
	int st;

	if (get->argv[1])
	{
		st = _atoi(get->argv[1]);
		if (st== -1)
		{
			get->status = 2;
			error_print("Illegal number: ");
			_puts(get->argv[1]);
			_putchar('\n');
			return (1);
		}
		return (-2);
	}

	return(-2);

}
/**
 * myhelp - changes the current directory of the process
 * @get: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int myhelp(in_arg *get)
{
	char *ag_array, f = 'W';

	ag_array =  get->argv[1];
	putchar(f);
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
