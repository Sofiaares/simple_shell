#include "shell.h"
/**
 * search_full_path - search for a valid paths for the command
 * @command: the comand that may look for in the path
 * Return: the fullpath if found , NULL otherwise.
 */

char *search_full_path(char *command)
{
	char *full_p_i;
	char **path_tkens;
	int j = 0, var_i;

	var_i = find_path_index("PATH");
	if (var_i == -1)
		return (NULL);
	path_tkens = parse_path(var_i, "PATH");
	if (!path_tkens)
		return (NULL);

	while (path_tkens[j])
	{
		full_p_i = (build_full_path(path_tkens[j], command));
		if (!full_p_i)
		{
			free_i(path_tkens);
			return (NULL);
		}
		if (access(full_p_i, X_OK) == 0)
		{
			free_i(path_tkens);
			return (full_p_i);
		}
		free_i(char *full_p_i);
		j++;
	}
	free_i(path_tkens);
	return (NULL);
}

/**
 * parse_path - finds environment variable in the environ and
 * split it into tokens.
 * @index: Indexing of the environment variable.
 * @vstr: represent the environment variable.
 * Return: on success an array of token, on fail NULL is returned.
 */
char **parse_path(int index, char *vstr)
{
	char *env_var; /*get_env("PATH");*/
	char **path_tkens;
	int rlen;
	const char *dylmtr = ":";

	rlen = _strlen_i(vstr);
	env_var = envi[index] + (rlen + 1);
	path_tkens = parse_path(env_var, dylmtr);
	if (path_tkens == NULL)
		return (NULL);
	return (path_tkens);
}
/**
 * build_full_path - Combine a tken in the tkens PATH array with a command.
 * @ypath: Represents a tken of the environment variable PATH.
 * @command_i: the command.
 * Return: On success a full path of the command, Otherwise NULL.
 */
char *build_full_path(char *ypath, char *command_i)
{
	int path_rlen_i;
	int command_ren;
	int rlen;
	char *built;

	if (ypath == NULL || command_i == NULL)
		return (NULL);
	path_rlen_i = _strlen_i(ypath);
	command_ren = _strlen_i(command_i);
	rlen = path_rlen_i + command_ren + 2;

	built = malloc(sizeof(char) * rlen);
	if (built == NULL)
		return (NULL);
	_str_cat_i(built, ypath);
	_str_copy_i(built, "/");
	_str_cat_i(built, command_i);
	return (built);
}

/**
 * path_index_finder - Finds an index of an environmental variable.
 * @envy: Environment variable that in need to be found.
 * Return: on success returns the index of the environment variable
 * otherwise returns -1
 */
int path_index_finder(char *envy)
{
	int j;
	int rlen;
	int x;

	rlen = _strlen_i(envy);
	for (j = 0; environ[j] != NULL; j++)
	{
		for (x = 0; x < rlen; x++)
		{
			if (envi[j][x] != envy[x])
				break;
		}
		if (x == rlen && environ[j][x] == '=')
			return (j);
	}
	return (-1);
}
