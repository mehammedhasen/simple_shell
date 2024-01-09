#include "shell.h"

/**
 * creat_hist_flpath - gets the history file (get_history_file)
 * @get: parameter struct
 *
 * Return: allocated string containg history file
 */

char *creat_hist_flpath(in_arg *get)
{
	char *buf, *fldir;

	fldir = _getenv(get, "HOME=");
	if (!fldir)
		return (NULL);
	buf = malloc(sizeof(char) * (_strlen(fldir) + _strlen(HISTORY_FILE) + 2));
	if (!buf)
		return (NULL);
	buf[0] = 0;
	_strcpy(buf, fldir);
	_strcat(buf, "/");
	_strcat(buf, HISTORY_FILE);
	return (buf);
}
/**
 * write_hist_fle - creates a file, or appends to an existing file
 * @get: the parameter struct
 *
 * Return: 1 on success, else -1
 */
int write_hist_fle(in_arg *get)
{
	ssize_t fd;
	char *flename = creat_hist_flpath(get);
	list_s *node = NULL;

	if (!flename)
		return (-1);

	fd = open(flename, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(flename);
	if (fd == -1)
		return (-1);
	for (node = get->history; node; node = node->next)
	{
		_putstr2fld(node->strg, fd);
		_putchar2fld('\n', fd);
	}
	_putstr2fld(get->str_ptr, fd);
	close(fd);
	return (1);
}
/**
 * read_hist_fle - reads history from file
 * @get: the parameter struct
 *
 * Return: histcount on success, 0 otherwise
 */
int read_hist_fle(in_arg *get)
{
	int i, last = 0, linenumber = 0;
	ssize_t fd, rdlen, fsize = 0;
	struct stat st;
	char *buf = NULL, *flename = creat_hist_flpath(get);

	if (!flename)
		return (0);

	fd = open(flename, O_RDONLY);
	free(flename);
	if (fd == -1)
		return (0);
	if (!fstat(fd, &st))
		fsize = st.st_size;
	if (fsize < 2)
		return (0);
	buf = malloc(sizeof(char) * (fsize + 1));
	if (!buf)
		return (0);
	rdlen = read(fd, buf, fsize);
	buf[fsize] = 0;
	if (rdlen <= 0)
		return (free(buf), 0);
	close(fd);
	for (i = 0; i < fsize; i++)
		if (buf[i] == '\n')
		{
			buf[i] = 0;
			creat_hist_list(get, buf + last, linenumber++);
			last = i + 1;
		}
	if (last != i)
		creat_hist_list(get, buf + last, linenumber++);
	free(buf);
	get->count_hist = linenumber;
	while (get->count_hist-- >= HIST_SIZE)
		delete_node_at_index(&(get->history), 0);
	recount_hist(get);
	return (get->count_hist);
}
/**
 * creat_hist_list - adds entry to a history linked list
 * @get: Structure containing potential arguments. Used to maintain
 * @buf: buffer
 * @linenumber: the history linecount, histcount
 *
 * Return: Always 0
 */
int creat_hist_list(in_arg *get, char *buf, int linenumber)
{
	list_s *node = NULL;

	if (get->history)
		node = get->history;
	ad_node_at_end(&node, buf, linenumber);

	if (!get->history)
		get->history = node;
	return (0);
}
/**
 * recount_hist - renumbers the history linked list after changes
 * @get: Structure containing potential arguments. Used to maintain
 *
 * Return: the new histcount
 */
int recount_hist(in_arg *get)
{
	list_s *node = get->history;
	int i = 0;

	while (node)
	{
		node->line = i++;
		node = node->next;
	}
	return (get->count_hist = i);
}
