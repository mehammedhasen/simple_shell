#include "shell.h"
/**
 * find_node_index - find index of a give node
 * @head: pointer to address of start of list head
 * @node: pointer to a node
 *
 * Return: index of node or -1
 */
int find_node_index(list_s **head, list_s *node)
{
	int index = 0;
	list_s *tmp;

	tmp = *head;
	while (tmp)
	{
		if (tmp == node)
			return (index);
		tmp = tmp->next;
		index++;
	}
	return (-1);
}

/**
 * pp_to_string - returns pointer of pointer the list_s->strg
 * @head: pointer to first node
 *
 * Return: pointer of pointer to list_s string
 */
char **pp_to_string(list_s *head)
{
	size_t n = 0;
	size_t k;
	size_t i;
	char **pptr = NULL;

	list_s *node;

	node = head;

	n = list_s_len(node);
	i = n;

	if (!node || !n)
		return (NULL);
	pptr = malloc(sizeof(char *) * (n + 1));
	if (!pptr)
		return (NULL);
	for (i = 0; node; i++)
	{
		pptr[i] = malloc(_strlen(node->strg) + 1);
		if (!pptr[i])
		{
			for (k = 0; k < i; k++)
				free(pptr[k]);
			free(pptr);
			return (NULL);
		}
		pptr[i] = _strcpy(pptr[i], node->strg);
		node = node->next;
	}
	pptr[i] = NULL;
	return (pptr);
}

/**
 * node_st_wtpref - returns node whose string starts with prefix
 * @head: pointer to list head
 * @prefix: string to match
 * @c: the next character after prefix to match
 *
 * Return: a match node or null
 */
list_s *node_st_wtpref(list_s *head, char *prefix, char c)
{
	char *ptr = NULL;

	while (head)
	{
		ptr = ch_st_vrname(head->strg, prefix);
		if (ptr && *ptr == c)
			return (head);
		head = head->next;
	}
	return (NULL);
}
