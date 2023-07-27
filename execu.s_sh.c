#include "shell.h"


/**
 * creates_process - create a child process which passed the command in
 * @argss: arr contains the command and its arguments
 * @envy: environ variable
 * Return: same as execve.
 */


void creates_process(char **argss, char *envy[])
{
	int statut;
	pid_t pids = fork();

	if (pids == 0)
	{
		if (execve(argss[0], argss, envy) == -1)
		{
			perror("Execve(): ");
		}
	}
	else if (pids == -1)
	{
		perror("Fork():");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(&statut);
	}
}
