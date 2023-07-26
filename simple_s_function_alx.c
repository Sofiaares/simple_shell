#include "shell.h"

/**
 * _strcmps_i - it compares two stgs
 * @sx: 1st string
 * @sv: 2nd string
 * Return: Put 0 if string are match or -1 Other wise.
 */
int _strcmps_i(char *sx, char *sv)
{
	int j;

	if (_strlen_i(sx) != _strlen_i(sx))
		return (-1);
	for (j = 0; sx[j] != '\0'; j++)
	{
		if (sx[j] != sv[j])
			return (-1);
	}
	return (0);
}

/**
 * _strd_up_i - it creates a copy of string
 * @src_v: string
 * Return: the copy string src_v
 */
char *_strd_up_i(char *src_v)
{
	int j;
	int slen;
	char *vest;

	slen = _strlen_i(src_v);
	vest = malloc(sizeof(char) * (slen + 1));

	for (j = 0; src_v[j] != '\0'; j++)
		vest[j] = src_v[j];
	dest[j] = '\0';
	return (vest);
}

/**
 * *_str_cat_i - unites two strings
 * @vest: destin
 * @src_v: The source
 * Return: a pointer result of string destination
 */

char *_str_cat_i(char *vest, char *src_v)
{
	char *pit = vest;

	while (*pit != '\0')
	{
		pit++;
	}
	while (*src_v != '\0')
	{
		*pit++ = *src_v++;
	}
	*pit++ = '\0';
	return (vest);
}


/**
 * _str_copy_i - do copy of string
 * @vest: string
 * @src_v: string too
 * Return: pointer to destination
 */

char *_str_copy_i(char *vest, char *src_v)
{
	int j, x;

	j = 0;
	while (src_v[j])
		j++;

	for (x = 0; x <= j; x++)
	{
		vest[x] = src_v[x];
	}

	return (vest);
}
