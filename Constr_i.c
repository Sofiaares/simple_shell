#include "shell.h"

/**
 * ourcod_i - to change the directory we work in
 * it can passed to it.
 * if there is no parameters that passed it can change dir to HOME.
 * @vargs: the command and its flags
 * @i_line: A string of the input from the executer.
 */

void ourcod_i(char **vargs, __attribute__((unused)) char *i_line)
{
	char *bux = NULL;
	size_t sizze = 0;
	int index;
	char *pxd = getcwd(bux, sizze);

	if (vargs[1] == NULL)
	{
		index = path_index_finder("HOME");
		ch_dir_i((envi_mntal[index]) + 5);
	}
	else if (_strcmps_i(vargs[1], "-") == 0)
	{
		index = path_index_finder("OLDPxD");
		if (index != -1)
			ch_dir_i((envi_mntal[index]) + 7);
		else
			perror("cd: ");
	}
	else
	{
		if (ch_dir_i(vargs[1]) == -1)
		{
			perror("error: ");
		}
	}
	set_env("OLDPxD", pxd);
	free_i(bux);
	free_i(pxd);
}

/**
 * ourenv_i - it Prints all variables environmental in the shell.
 * @q: the command and flags , but it may not be used here
 * @r: A string of input from the user. also may not be used.
 */
void ourenv_i(__attribute__((unused)) char **q, __attribute__((unused)) char *r)
{
	int j;

	for (j = 0; envi_mntal[j] != NULL; j++)
	{
		_puts_i(envi_mntal[j]);
		_puts_i("\n");
	}
}

/**
 * ourext_i - it exit shell. After frees allocs.
 * @vargs: the command and all flags
 * @i_line: A string of the input.
 */
void ourext_i(char **vargs, char *i_line)
{
	int STATUS = exit_success;
	int j = 0;

	if (vargs[1])
	{
		while (vargs[1][j])
		{
			if (!_i_sdigit(vargs[1][j]))
				break;
			j++;
		}
		if (j == _strlen_i(vargs[1]))
			status = _atoi(vargs[1]);
	}
	else
		STATUS = exit_success;

	free_i(i_line);
	free_arr(vargs);
	exit(STATUS);
}

#include "shell.h"

/**
 * ourseten_v_i - starts a new variable environmental,
 * or it may modify an existing one
 * @vargs: the variables array
 * @i_line: the input from the excuter
 */
void ourseten_v_i(char *vargs[], __attribute__((unused)) char *i_line)
{
	char *name_i, *vlue_i;

	if (!vargs[2] || !vargs[1])
	{
		perror("seten_v_i()");
		return;
	}
	name_i = vargs[1];
	vlue_i = vargs[2];
	set_env(name_i, vlue_i);
}
/**
 * our_unseten_v_i - not set variable environmental name
 * @vargs: array of tkens it contains var name to unset vargs.
 * @i_line: the input that excuter typed or given by mode non-interactive.
 */
void our_unseten_v_i(char *vargs[], __attribute__((unused)) char *i_line)
{
	int index;
	char *name_i = vargs[1];

	if (!name_i)
		return;
	index = path_index_finder(name_i);
	if (index != -1)
	{
		envi_mntal[index] = envi_mntal[index + 1];
	}
	else
		perror("unseten_v_i() ");
}
