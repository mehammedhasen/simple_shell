#include"shell.h"
/**
* excute_com - excute file based on command chain
* @get : argument arry arrt
* @buffer : buffer input
* @envp : env varb
i* Return: void
*/
void excute_com(in_arg *get, char *buffer, char **envp)
{

	char  c;

	c = check_bufchain(buffer);
	if (c == ';')
	{
	excu_semicol(get, buffer, envp);
	}
	else if (c == '&')
	{
	excu_and(get, buffer, envp);
	}
	else if (c == '|')
	{
	excu_or(get, buffer, envp);
	}	/*excute fot OR chain comand*/
	else if (c == ' ') /*ecute fot normal input*/
	{
	excu_space(get, buffer, envp);
	}
	else if (c == '$') 
	{
	handle_echo_variable(buffer);/*func to prt echo $*/
	}
	else 
		print_prompt();
}
