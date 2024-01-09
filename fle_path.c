#include "shell.h"

/**
 * get_envpath - Returns the value of the PATH enviroment variable.
 *@get: default argument of function
 * Return: Pointer to the value of $PATH.
 */
char *get_envpath(in_arg *get)
{
	char *finder;

	finder = _getenv(get, "PATH=");

	return (finder);
}

/**
 * find_file_path - Looks for a command in each directory specified in the PATH
 *                environment variable
 * @get: Structure containing potential arguments.
 * @envpath:string value of PATH vrb
 * @comd: pointer to comd string to look for path
 *
 * Return: pointer to string containing the full path (success) if it is found,
 *         or NULL if it is not found (failure).
*/
char *find_file_path(in_arg *get, char *envpath, char *comd)
{
	struct stat st;
	int stat_path = 0, i;
	char buf[PATH_MAX],  *path = NULL, **dir = NULL;

	envpath = _getenv(get, "PATH=");
	if (!envpath)
		return (NULL);
	dir = str_token(envpath, ':');
	if (!dir)
		return (NULL);
	for (i = 0; dir[i]; i++)
	{
		_memset(buf, 0, PATH_MAX);
		_strcpy(buf, dir[i]);
		_strcat(buf, "/");
		_strcat(buf, comd);
		stat_path = stat(buf, &st);
		if (stat_path == 0 && S_ISREG(st.st_mode) && (st.st_mode & S_IXUSR))
		{
			free(dir);
			path = malloc(sizeof(char) * (strlen(buf) + 1));
			if (!path)
				return (NULL);
			_strcpy(path, buf);
			return (path);
		}
	}
	if (stat_path == -1)
		free(dir);
	return (NULL);
}
