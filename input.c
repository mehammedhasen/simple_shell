#include "shell.h"
/**
 * input_str - gets a line of inputs minus the newline
 * @get: parameter struct
 *
 * Return: bytes read
 */

int input_str(in_arg *get)
{
	ssize_t rd;
	int i = 0;
	size_t by = 0;
	char *buf_ptr = NULL;
	char **argve = NULL;

	if (ch_interactive())
		print_prompt();

	rd = getline(&buf_ptr, &by, stdin);
	
	get->str_ptr = buf_ptr;
	get->argv = argve;
	if (buf_ptr[rd - 1] == '\n')
		buf_ptr[rd - 1] = '\0';
	rd--;

	delet_comment(get->str_ptr);
	write_hist_fle(get);
	argve = str_token(get->str_ptr, ' ');
	get->argv = argve;
	if (!get->argv)
	{
		get->argv = malloc(sizeof(char *) * 2);
			if (get->argv)
			{
				get->argv[0] = _strdup(get->str_ptr);
				get->argv[1] = NULL;
			}
	}
	while(get->argv[i] != 0)
		i++;
	get->argc = i;

	return (i);
}
/**
 * delet_comment - function replaces first instance of '#' with '\0'
 * @bufin: address of the string input to buf
 *
 */
void delet_comment(char *bufin)
{
	int i;

	for (i = 0; bufin[i] != '\0'; i++)
		if (bufin[i] == '#' && (!i || bufin[i - 1] == ' '))
		{
			bufin[i] = '\0';
			break;
		}
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
