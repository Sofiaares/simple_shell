#include "shell.h"
/**
 * _puts_i - do thing
 * @q: string
 * Return: void
 */
void _puts_i(char *q)
{
	if (*q != '\0')
	{
		_putchar(*q);
		_puts_i(q + 1);
	}
}

/**
 * _strlen_i - it returns the length of string
 * @q: string
 * Return: void
 */
int _strlen_i(char *q)
{
	if (*q != '\0')
		return (1 + _strlen_i(q + 1));
	else
		return (0);
}

/**
 * free_i - it free an array
 * @arri: array to free_i
 */
void free_i(char **arri)
{
	int j;

	for (j = 0; arri[j]; j++)
	{
		free_i(arr[j]);
	}
	free_i(arri);
}

/**
 * print_num_i - capitaliz words of a string.
 * @n: nrr
 * Return: void
 */

void print_num_i(int n)
{
	unsigned int nrr;

	nrr = n;
	if (n < 0)
	{
		_putchar('-');
		nrr = -n;
	}
	if (nrr / 10)
	{
		print_num_i(nrr / 10);
	}
	_putchar(nrr % 10 + '0');
}

/**
 * _putchar - it writes a character c to st dout
 * @c: A character to use and print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is all set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
