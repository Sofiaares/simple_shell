#include "shell.h"

/**
 * error_handl_i - print error when execve .. it fails.
 * @vargs: args vects.
 * @command: command of arguments.
 * @cmd_counter_i: it counts throw how many time a command was entered.
 */

void error_handl_i(char *vargs[], char *command[], int cmd_counter_i)
{
	_puts_i(vargs[0]);
	_puts_i(": ");
	print_number(cmd_counter_i);
	_puts_i(": ");
	_puts_i(command[0]);
	_puts_i(": not found\n");
}
