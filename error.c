#include "shell.h"
/**
 * _putchar2fld - writes the character c to given fd
 * @c: The character to print
 * @fld: The filedescriptor to write to
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar2fld(char c, int fld)
{
	static int i;
	static char buf[BUF_SIZE];

	buf[i++] = c;

	return (write(fld, buf, i));

}

/**
 *_putstr2fld - prints an input string
 * @strg: the string to be printed
 * @fld: the filedescriptor to write to
 *
 * Return: the number of chars put
 */
int _putstr2fld(char *strg, int fld)
{
	int i = 0;

	if (!strg)
		return (0);
	while (*strg)
	{
		i += _putchar2fld(*strg++, fld);
	}
	return (i);
}

#include "shell.h"

/**
 *_put_str_er - prints an input string
 * @strg: the string to be printed
 *
 * Return: Nothing
 */
void _put_str_er(char *strg)
{
	int i = 0;

	if (!strg)
		return;
	while (strg[i] != '\0')
	{
		_put_char_er(strg[i]);
		i++;
	}
}


/**
 * _put_char_er - writes the character c to stderr
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _put_char_er(char c)
{
	static int i;
	static char buf[BUF_SIZE];

	buf[i++] = c;

	return (write(2, buf, i));
}
