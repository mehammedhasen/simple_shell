#include "shell.h"

/**
 * _strcpy - copies a string
 * @destr: the destination
 * @srstr: the source
 *
 * Return: pointer to destination
 */
char *_strcpy(char *destr, char *srstr)
{
	int i = 0;

	if (destr == srstr || srstr == 0)
		return (destr);
	while (*srstr)
	{
		destr[i] = *srstr++;
		i++;
	}
	destr[i] = 0;
	return (destr);
}
/**
 * _strdup - duplicates a string
 * @str: the string to duplicate
 *
 * Return: pointer to the duplicated string
 */
char *_strdup(const char *str)
{
	int len = 0;
	int i = 0;
	char *dup;

	if (str == NULL)
		return (NULL);
	while (*str++)
		len++;
	dup = (char *)malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (NULL);
	while (i <= (len + 1))
	{
		dup[i] = str[i];
		i++;
	}

	return (dup);

}

/**
 * _puts - prints an input string
 * @strg: the string to be printed
 *
 * Return: Nothing
 */
void *_puts(char *strg)
{
	int i = 0;

	if (!strg)
	return (NULL);
	while (strg[i] != '\0')
	{
		_putchar(strg[i]);
		i++;
	}
	return  (NULL);

}


/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{

	return (write(1, &c, 2));
}
