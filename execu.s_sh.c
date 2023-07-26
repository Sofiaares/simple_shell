#include "shell.h"


/**
 * execute_process_i - it creates a source process it passed the command which
 * execute in
 * @vargs: an array that contains command and all arguments
 * @envy: variables
 * Return: same thing as exec_ve.
 */


void execute_process_i(char **vargs, char *envy[])
{
	int status;
	pid_t pid_i = fork();

	if (pid_i == 0)
	{
		if (exec_ve(vargs[0], vargs, envy) == -1)
		{
			perror("Exec_ve(): ");
		}
	}
	else if (pid_i == -1)
	{
		perror("Fork():");
		exit(exit_failure);
	}
	else
	{
		wait(&status);
	}
}
