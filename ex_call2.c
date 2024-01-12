#include "shell.h"
/**
* excu_or - function to run for or
* @buf:buffer 
* @get: argume
* @envp: envar argu
* Return: void
*/
void excu_or(in_arg *get,char *buf, char **envp)
{	
	char *ex_path;
	int i = 0;

	get->argv = tok_str(buf, "||");
	free(buf);
	while (get->argv[i] != NULL)
	{
		ex_path = find_file_path(get->argv[i]);
		free(get->argv[i]);
		get->argv[i] = ex_path;
		free(ex_path);
		if (execve(get->argv[i], get->argv, envp) == -1)
		{
			_puts("cannot access get->argv[i]");
			i++;
		}
		else
		{
		i++;
		get->argv[i] = NULL;
		clear_arg(get);
		_putchar('\n');
                }
	}
}
/**
* excu_and - function to run for and
* @buf:buffer 
* @get : argum
* @envp :envir argum
* Return: void
*/
void excu_and(in_arg *get,char *buf, char **envp)
{	
	char *ex_path;
	int i = 0;
	get->argv = tok_str(buf, "&&");
	free(buf);
	while(get->argv[i] != NULL)
	{
		ex_path = find_file_path(get->argv[i]);
		free(get->argv[i]);
                get->argv[i] = ex_path;
		free(ex_path);
		if (execve(get->argv[i], get->argv, envp) == -1)
		{       _puts("cannot access get->argv[i]");
			i++;
			get->argv[i] = NULL;
			clear_arg(get);
			_putchar('\n');
		}
		else
		i++;
	}
}
/**
 * check_comment- function replaces first instance of '#' with '\0'
 * @buf: address of the string input to buf
 *
 * Return: buf ponter;
 */
char *check_comment(char *buf)
{	char **dlecom = NULL;
	dlecom = str_token(buf, '#');
	free(buf);
	dlecom[1] = NULL;
	buf = dlecom[0];
	free(dlecom[0]);

return (buf);
}
/**
* print_prompt - function print out prompr sign
* Return: prompt sign
*/
void print_prompt(void)
{
	char prom = '$';

	write(1, &prom, 2);
}
