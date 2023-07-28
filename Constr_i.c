#include "shell.h"

/**
 * our_cod - Changes the current working directory to
 * the directory passed to it.
 * if no parameter is passed it will change directory to HOME.
 * @argss: the command and its flags
 * @eline: A string representing the input from the user.
 */

void our_cd(char **argss, __attribute__((unused)) char *eline)
{
	char *bxf = NULL;
	size_t size = 0;
	int index;
	char *pwd = getcwd(bxf, size);

	if (argss[1] == NULL)
	{
		index = find_path_index("HOME");
		chdir((environ[index]) + 5);
	}
	else if (_strcmp_(argss[1], "-") == 0)
	{
		index = find_path_index("OLDPWD");
		if (index != -1)
			chdir((environ[index]) + 7);
		else
			perror("cd: ");
	}
	else
	{
		if (chdir(argss[1]) == -1)
		{
			perror("error: ");
		}
	}
	set_env("OLDPWD", pwd);
	free(bxf);
	free(pwd);
}

/**
 * our_env - Prints all the environmental variables in the current shell.
 * @m: the command and its flags , but not used here
 * @t: A string representing the input from the user. also not used.
 */
void our_env(__attribute__((unused)) char **m, __attribute__((unused)) char *t)
{
	int j;

	for (j = 0; environ[j] != NULL; j++)
	{
		_puts(environ[j]);
		_puts("\n");
	}
}

/**
 * our_exit - Exits the shell. After freeing allocated resources.
 * @argss: the command and its flags
 * @eline: A string representing the input from the user.
 */
void our_exit(char **argss, char *eline)
{
	int status = EXIT_SUCCESS;
	int j = 0;

	if (argss[1])
	{
		while (argss[1][j])
		{
			if (!_isdigit_(argss[1][j]))
				break;
			j++;
		}
		if (j == _strlen(argss[1]))
			status = _atoi(argss[1]);
	}
	else
		status = EXIT_SUCCESS;

	free(eline);
	free_arr(argss);
	exit(status);
}

#include "shell.h"

/**
 * our_setenv - Initialize a new environment variable,
 * or modify an existing one
 * @argss: the variables array
 * @eline: the input from the user
 */
void our_setenv(char *argss[], __attribute__((unused)) char *eline)
{
	char *na, *valu;

	if (!argss[2] || !argss[1])
	{
		perror("setenv()");
		return;
	}
	na = argss[1];
	valu = argss[2];
	set_env(na, valu);
}
/**
 * our_unsetenv - unset the environment variable name
 * @argss: array of tokens containing the var name to unset args[1].
 * @eline: the input typed by the user or given by non-interactive mode.
 */
void our_unsetenv(char *argss[], __attribute__((unused)) char *eline)
{
	int index;
	char *na = argss[1];

	if (!na)
		return;
	index = find_path_index(na);
	if (index != -1)
	{
		environ[index] = environ[index + 1];
	}
	else
		perror("unsetenv() ");
}
