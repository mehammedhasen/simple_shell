#include "shell.h"

/**
 * ch_interactive - returns true if shell is interactive mode
 * @get: input string file
 *
 * Return: 1 if interactive mode, 0 otherwise
 */

int ch_interactive(in_arg *get)
{
	int i = isatty(in_arg *get);

	return (i);
}


/**
 * is_delim - checks if character is a delimeter
 * @c: the char to check
 * @delim: the delimeter stringi
 * Return: 1 if true, 0 if false
 */
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 *_isalpha - checks for alphabetic character
 *@c: The character to input
 *Return: 1 if c is alphabetic, 0 otherwise
 */

int _isalpha(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 *_atoi - converts a string to an integer
 *@strg: the string to be converted
 *Return: 0 if no numbers in string, converted number otherwise
 */

int _atoi(char *strg)
{
	int i, sign = 1, flag = 0;
	unsigned int num = 0;

	while ((strg[i] != '\0') && (flag != 2))
	{
		if (strg[i] == '-')
			sign *= -1;

		if (strg[i] >= '0' && strg[i] <= '9')
		{
			flag = 1;
			num *= 10;
			num += (strg[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
		i++;
	}

	return (num * sign);
}
/**
 * _memset - fills memory with a constant byte
 * @s: the pointer to the memory area
 * @b: the byte to fill *s with
 * @n: the amount of bytes to be filled
 * Return: (s) a pointer to the memory area s
 */

char *_memset(char *s, char b, size_t n)
{
	unsigned int i;

	n =  sizeof(s);

	for (i = 0; i < n; i++)
		s[i] = b;
	return (s);
}
