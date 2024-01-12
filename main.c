#include "shell.h"
/**
 * main - entry point
 * @arg_co: argument num
 * @arg_vec: argument vec
 * @envp: eniroment var
 * Return: 0 on success, 1 on error
 */
int main(int arg_co, char **arg_vec, char **envp)
{
	in_arg get[] = {ALL_ARGUMENT};
	int flred = 2, status;
	static char buf[BUF_SIZE];

	pid_t fpid;

	while (arg_co == 2)
	{
	flred = open(arg_vec[1], O_RDONLY);
	ch_interactive();
	print_prompt();
	read(flred, buf, sizeof(flred));
	check_comment(buf);
	fpid = fork();
	if (fpid == -1)
	{
	perror("Error fork()");
	clear_arg(get);
	print_prompt();
	}
	if (fpid == 0)
	excute_com(get, buf, envp);
	else
	waitpid(fpid, &status, 0);

	if (WIFSIGNALED(status))
		error_print("signa inter-rupt");
	else if (WEXITSTATUS(status))
		_puts("pls exit normaly");

	}
	return (0);
}


