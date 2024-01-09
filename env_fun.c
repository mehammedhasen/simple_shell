#include "shell.h"

/**
 * alloc_environ - returns the array of pointer of  environ
 * @get: Structure containing potential arguments
 * Return: Always 0
 */
char **alloc_environ(in_arg *get)
{
	get->environ = pp_to_string(get->env);

	return (get->environ);
}

/**
 * listdown_all_env - populates env linked list
 * @get: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int listdown_all_env(in_arg *get)
{
	list_s *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		ad_node_at_end(&node, environ[i], 0);
	get->env = node;
	return (0);
}
/**
 * _getenv - gets the value of an environ variable
 * @get: Structure containing potential arguments. Used to maintain
 *@vrname: env variable name
 * Return: the value of variable name
 */
char *_getenv(in_arg *get, const char *vrname)
{
	list_s *node = get->env;
	char *vlue;

	while (node)
	{
		vlue = ch_st_vrname(node->strg, vrname);
		if (vlue && *vlue)
			return (vlue);
		node = node->next;
	}
	return (NULL);
}


/**
 * env - prints all environment
 * @get: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int myenv(in_arg *get)
{
	print_strg_in_alnode(get->env);
	return (0);
}

/**
 * _unsetenv - Remove an environment variable
 * @get: Structure containing potential arguments. Used to maintain
 *
 * @name: env variab name       
 *  Return: 1 on delete, 0 otherwise
 */
int _unsetenv(in_arg *get, char *name)
{
	unsigned int  i = 0;
	list_s *node = get->env;
/*	char *name = get->argv[1];*/
	char *vlue;

	while (node)
	{
		vlue = ch_st_vrname(node->strg, name);
		if (vlue && *vlue == '=')
		{
			get->env_flag = delete_node_at_index(&node, i);
			i = 0;
			node = get->env;
			continue;
		}
		node = node->next;
		i++;
	}
	return (get->env_flag);
}

/**
* mk_env_str - creat pointer of link strg
* @vrname: env variable name
* @vrvalue: env variable value
* Return: if success re-pointer if not return -1
*/

char *mk_env_str(char *vrname, char *vrvalue)
{
	char *buf = NULL;

	buf = malloc(_strlen(vrname) + _strlen(vrvalue) + 2);
	if (!buf)
		return (NULL);
	_strcpy(buf, vrname);
	_strcat(buf, "=");
	_strcat(buf, vrvalue);
	return (buf);
}
/**
 * _setenv - Initialize a new env varb,
 *             or modify an existing one
 * @get: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * @name: env variab name
 * @value: env varib value
 *  Return: Always 0
 */
int _setenv(in_arg *get, char *name, char *value)
{

	list_s *node = get->env;
	char *nodstr;
	char *vlue;

/*	get->argv[1] = name;*/
/*	get->argv[2] = value;*/
	

	if (get->argc >= 3)
	{
		if (!name || !value)
			return (0);
		nodstr = mk_env_str(name, value);

		while (node)
		{
			vlue = ch_st_vrname(node->strg, name);
			if (vlue && *vlue == '=')
			{
				free(node->strg);
				node->strg = nodstr;
				get->env_flag = 1;
				return (1);
			}
			node = node->next;
		}
		ad_node_at_end(&(get->env), nodstr, 0);
	}
	free(nodstr);
	get->env_flag = 1;
	return (1);
}
/**
 * mysetenv - Initialize a new environment variable,
 *             or modify an existing one
 * @get: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int mysetenv(in_arg *get)
{
	if (get->argc != 3)
	{
		_puts("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(get, get->argv[1], get->argv[2]))
		return (0);
	return (1);
}
/**
 * myunsetenv - Remove an environment variable
 * @get: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int myunsetenv(in_arg *get)
{
	int i;

	if (get->argc == 1)
	{
		_puts("Too few arguements.\n");
		return (1);
	}
	for (i = 1; i <= get->argc; i++)
		_unsetenv(get, get->argv[i]);

	return (0);
}
