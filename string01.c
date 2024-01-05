#include "shell.h"

/**
 * _strlen - returns the length of a string
 * @strg: the string whose length to check
 *
 * Return: integer length of string
 */
int _strlen(char *strg)
{
	int i = 0;

	if (!strg)
		return (0);

	while (strg[i] != '\0')
		i++;
	return (i);

}

/**
 * _strcmp - performs lexicogarphic comparison of two strangs.
 * @strg1: the first string
 * @strg2: the second string
 *
 * Return: negativ if strg1 > strg2, zero if strg1 == strg2
 */
int _strcmp(char *strg1, char *strg2)
{
	while (*strg1 && *strg2)
	{
		if (*strg1 != *strg2)
		{
			if (*strg1 > *strg2)
				return (1);
			else
				return (-1);
		}

		strg1++;
		strg2++;
	}
	return (0);	
}
/**
 * ch_st_vrname - checks if value str is in name enviro variable
 * @nstr: string of enviromental variable to be find
 * @vstr: string of assign variable name with env value
 *
 * Return: address of value with = from environ
 */
char *ch_st_vrname(const char *vstr, const char *nstr)
{
	while (*nstr)
		if (*nstr++ != *vstr++)
			return (NULL);
	return ((char *)vstr);
}

/**
 * _strcat - concatenates two strings
 * @dest: the destination buffer
 * @src: the source buffer
 *
 * Return: pointer to destination buffer
 */
char *_strcat(char *dest, char *src)
{
	char *con = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	return (con);
}
