#include "shell.h"
/**
 * _wordcount - counts number of words
 * @get: string input
 * @dl :delimer char
 * Return: int
 */
int _wordcount(in_arg *get, char dl)
{
	int l, wc;
	char *sw = get->str_ptr;

	l = 0, wc = 0;
	if (*(sw + l) == dl)
		l++;
	while (*(sw + l))
	{
	if (*(sw + l) == dl && *(sw + l - 1) != dl)
		wc++;
	if (*(sw + l) != dl   && *(sw + l + 1) == 0)
		wc++;
	l++;
	}
	return (wc);
}
/**
 * _trspace - Moves adress to remove trailig whitespaces
 * @get: string input
 * @dl:delimeter character
 * Return: Pointer
 */
char *_trspace(in_arg *get, char dl)
{
	char *st = get->str_ptr;

	while (*st == dl)
		st++;
	return (st);
}
/**
 * str_token - splits a string into words
 * @get: string input
 * @dl :delimeter character
 * Return: Double Pointer
 */
char **str_token(in_arg *get, char dl)
{
	char **s, *ts;
	int l, l2, wc, i, j, fr, k;
	char *str = get->str_ptr;

	if (str == NULL || *str == 0)
		return (0);
	fr = 0;
	wc = _wordcount(str, dl);
	if (wc == 0)
		return (0);
	s = malloc((wc + 1) * sizeof(char *));
	if (s == 0)
		return (0);
	ts = _trspace(str, dl);
	for (i = 0; i < wc; i++)
	{
		l = 0;
		while (*(ts + l) != ' ' && *(ts + l) != 0)
			l++;
		s[i] = malloc((l + 1) * sizeof(char));
		if (s[i] == 0)
		{
		fr = 1;
		break;
		}
		for (j = 0, l2 = 0; l2 < l; l2++, j++)
			s[i][j] = *(ts + l2);
		s[i][j] = '\0';
		ts = _trspace((ts + l), dl);
	}
	s[i] = NULL;
	if (fr == 1)
	{
		for (k = 0; k <= i; k++)
		free(s[k]);
		free(s);
	}
	return (s);
}
