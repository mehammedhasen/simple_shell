#include "shell.h"

/**
 * ad_node - adds a node to the start of the list
 * @head: address of pointer to head node
 * @strg: string of  node
 * Return: address of the first node or list
 */

list_s *ad_node(list_s **head, const char *strg)
{
	list_s *nw_node;

	if (!head)
		return (NULL);
	nw_node = malloc(sizeof(list_s));
	if (!nw_node)
		return (NULL);
	if (strg)
	{
		nw_node->strg = strdup(strg);
		if (!nw_node->strg)
		{
			free(nw_node);
			return (NULL);
		}
	}
	nw_node->next = *head;
	*head = nw_node;
	return (nw_node);
}

/**
 * ad_node_at_end - adds a node to the start of the list
 * @head: address of pointer to head node
 * @strg: string of  node
 * Return: address of the last node or list
 */

list_s *ad_node_at_end(list_s **head, const char *strg, int line)
{
	list_s *nw_node, *node;

	if (!head)
		return (NULL);
	nw_node = malloc(sizeof(list_s));
	if (!nw_node)
		return (NULL);
	_memset((void *)nw_node, 0, sizeof(list_s));
	nw_node->line = line;
	if (strg)
	{
		nw_node->strg = strdup(strg);
		if (!nw_node->strg)
		{
			free(nw_node);
			return (NULL);
		}
	}
	node = *head;
	if (node)
	{
		while (node->next)
			node = node->next;
		node = nw_node;
	}
	else
		*head = nw_node;
	return (nw_node);
}

/**
 * list_s_len -  returns the number of elements in a linked list_s list
 * @head: head pointer of singly linked list
 * Return: Number of elements in list
 */
size_t list_s_len(const list_s *head)
{
	unsigned int size = 0;

	while (head != 0)
		head = head->next, size++;

	return (size);
}
/**
 * print_strg_in_alnode- prints the string element of a list_s linked list
 * @head: pointer to first node
 * Return: size of list
 */
size_t print_strg_in_alnode(const list_s *head)
{
	size_t size = 0;

	while (head)
	{
		_puts(head->strg ? head->strg : "(nil)");
		_putchar('\n');
		head = head->next;
		size++;
	}
	return (size);

}

/**
 * delete_node_at_index - deletes the node at index index a list_s linked list
 * @head: pointer to head of singly linked list
 * @index: index of the list where we want to delete a node
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_node_at_index(list_s **head, unsigned int index)
{
	unsigned int len = list_s_len(*head), count = 0;
	list_s *tmp1, *tmp2, *tmp3;

	if (*head == 0)
		return (-1);

	if (len == 1 && index == 0)
	{
		free(*head);
		*head = 0;
		return (1);
	}

	if (index > len - 1)
		return (-1);

	tmp1 = *head;
	while (count < index && index != 0)
	{
		tmp2 = tmp1;
		tmp1 = tmp1->next;
		tmp3 = tmp1->next;
		count++;
	}
	if (index == 0)
	{
		*head = tmp1->next;
		free(tmp1);
	}
	else
	{
		tmp2->next = tmp3;
		free(tmp1);
	}
	return (1);
}

/**
 * free_all_node - frees memory of a list
 * @head: pointer to head of singly linked list
 * Return: No Return
 */

void free_all_node(list_s **head)
{
	list_s *tmp;

	if (head)
	{
		while (*head != 0)
		{
			tmp = *head;

			*head = tmp->next;

			free(tmp);
		}
	}
}
