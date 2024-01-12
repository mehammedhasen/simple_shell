#include "shell.h"
/**
* excu_space - function to run for space
* @buf:buffer
* @get : argument
* @envp : envir argume
* Return: void
*/
void excu_space(in_arg *get, char *buf, char **envp)
{
	char *ex_path;
	int i = 0;

	get->argv = str_token(buf, ' ');
	free(buf);
	while (get->argv[i] != NULL)
	{
		ex_path = find_file_path(get->argv[i]);
		free(get->argv[i]);
		get->argv[i] = ex_path;
		free(ex_path);
		execve(get->argv[i], get->argv, envp);
		i++;
	}
	clear_arg(get);
	_putchar('\n');
}
/**
* excu_semicol - function to run for semicole ;
* @buf:buffer
* @get: argumen
* @envp:envargument
* Return: void
*/
void excu_semicol(in_arg *get, char *buf,char **envp)
{
	char *ex_path;
	int i = 0;

	get->argv = str_token(buf, ';');
	free(buf);
	while (get->argv[i] != NULL)
	{
		ex_path = find_file_path(get->argv[i]);
		free(get->argv[i]);
		get->argv[i] = ex_path;
		free(ex_path);
		execve(get->argv[i], get->argv, envp);
		i++;
	}
	clear_arg(get);
	_putchar('\n');
}
/**
* handle_echo_variable:funcion write value of enviromental varb
* @buf :input data argment
* Return : write value
*/
void handle_echo_variable(char *buf)
{
	char *env_name = NULL;
	char *env_value = NULL, **name;

	env_name = buf + 6;
	name = str_token(env_name, ' ');
	env_name = name[0];
	env_value = getenv(env_name);
	write(1, env_value, strlen(env_value));
	free (env_value);
	_putchar('\n');

}
