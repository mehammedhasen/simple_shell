#include "shell.h"
/**
 * _getline - gets the next line of input from stream
 * @rd: byte size
 * @buptr: address of pointer to buffer, preallocated or NULL
 *
 * Return: return i size
 */
size_t _getline(char **buptr, size_t *rd)
{
	static char *rdbuf;
	static size_t i;
	ssize_t k = 0;
	char *ptr = NULL;

	if (*buptr == NULL)
	{
		*rd = 1024;
		*buptr = (char *)malloc(*rd);
	}
	if (*buptr == NULL)
		return (-1);
	rdbuf = *buptr;
	do {
		k = read(STDIN_FILENO, rdbuf++, 1);
		i += k;
		if (i >= *rd - 1)
		{
			*rd *= 2;
			ptr = realloc(*buptr, *rd);
			if (ptr == NULL)
			{	free(*buptr);
				return (-1);
			}
		}
		*buptr = ptr;
		rdbuf = *buptr + i;
	} while (rdbuf[i - 1] != '\n');

	if (i == 0)
	{
		free(*buptr);
		return (-1);
	}
	rdbuf[i] = '\0';
	return (i);
}
