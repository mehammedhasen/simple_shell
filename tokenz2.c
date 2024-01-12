#include "shell.h"

/**
 * **tok_str - splits a string into words.
 * @strg: the input string
 * @dlmter: the delimeter string
 * Return: a pointer to an array of strings, or NULL on failure
 */

char **tok_str(char *strg, char *dlmter)
{
	int i, j, k, m, wordcount = 0;
	char **str_array;

	if (strg == NULL || strg[0] == 0)
		return (NULL);
	if (!dlmter)
		dlmter = " ";
	for (i = 0; strg[i] != '\0'; i++)
		if (!is_delim(strg[i], dlmter) &&
				(is_delim(strg[i + 1], dlmter) || !strg[i + 1]))
			wordcount++;

	if (wordcount == 0)
		return (NULL);
	str_array = malloc((1 + wordcount) * sizeof(char *));
	if (!str_array)
		return (NULL);
	for (i = 0, j = 0; j < wordcount; j++)
	{
		while (is_delim(strg[i], dlmter))
			i++;
		k = 0;
		while (!is_delim(strg[i + k], dlmter) && strg[i + k])
			k++;
		str_array[j] = malloc((k + 1) * sizeof(char));
		if (!str_array[j])
		{
			for (k = 0; k < j; k++)
				free(str_array[k]);
			free(str_array);
			return (NULL);
		}
		for (m = 0; m < k; m++) 
		str_array[j][m] = strg[i++];
		str_array[j][m] = 0;
	}
	str_array[j] = NULL;
	return (str_array);
}
