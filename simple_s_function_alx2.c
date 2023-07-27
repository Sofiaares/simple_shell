#include "shell.h"
/**
 * _puts - prints a string
 * @y: string
 * Return: void
 */
void _puts(char *y)
{
	if (*y != '\0')
	{
		_putchar(*y);
		_puts(y + 1);
	}
}

/**
 * _strlen - return the length of a string
 * @y: str
 * Return: lrength
 */
int _strlen(char *y)
{
	if (*y != '\0')
		return (1 + _strlen(y + 1));
	else
		return (0);
}

/**
 * free_arr - free array
 * @arr1: array to free
 */
void free_arr(char **arr1)
{
	int j;

	for (j = 0; arr1[j]; j++)
	{
		free(arr1[j]);
	}
	free(arr1);
}

/**
 * print_number - capitaliz any word of a string.
 * @v: num
 * Return: void
 */

void print_number(int v)
{
	unsigned int v1;

	v1 = v;
	if (v < 0)
	{
		_putchar('-');
		v1 = -v;
	}
	if (v1 / 10)
	{
		print_number(v1 / 10);
	}
	_putchar(v1 % 10 + '0');
}

/**
 * _putchar - writs the character c to stdout
 * @ch: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char ch)
{
	return (write(1, &ch, 1));
}
