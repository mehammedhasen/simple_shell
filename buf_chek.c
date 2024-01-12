#include"shell.h"
/**
 * check_bufchain - test if current char in buffer is a chain delimeter
 * @buf: the char buffer
 *
 * Return: 1 if chain delimeter, 0 otherwise
 */
int  check_bufchain(char *buf)
{
	int j = 0, i;
	char c;

	i = _strlen(buf);
	while (j != i)
	{
		if (buf[j] == ';')
		{
		c = ';';
		j = i;
		}
	else if (buf[j] == '&' && buf[j + 1] == '&')
		{
		c = '&';
		j = i;
		}
	else if (buf[j] == '|' && buf[j + 1] == '|')  /* found end of this command */
		{
		c = '|';
		j = i;
		}
	else if (buf[j] == ' ')
		{
		c = ' ';
		j = i;
		}
	else
		{
		c = '$';
		j = i;
		}
	}
	return (c);

}

