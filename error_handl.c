#include "shell.h"

/**
 * handle_exe_err - pings error when execve .. fails.
 * @argvs: args vector.
 * @comands: command and its args.
 * @cmdcounter: counts thw how much time a command was entered.
 */

void handle_exe_err(char *argvs[], char *comands[], int cmdcounter)
{
	_puts(argvs[0]);
	_puts(": ");
	print_number(cmdcounter);
	_puts(": ");
	_puts(comands[0]);
	_puts(": not found\n");
}
