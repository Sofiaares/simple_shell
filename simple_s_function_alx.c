#include "shell.h"

/**
 * _strcmp_ - compare two strings
 * @b1: First string
 * @b2: Second string
 * Return: 0 if strings match. -1 Otherwise.
 */
int _strcmp_(char *b1, char *b2)
{
	int j;

	if (_strlen(b1) != _strlen(b2))
		return (-1);
	for (j = 0; b1[j] != '\0'; j++)
	{
		if (b1[j] != b2[j])
			return (-1);
	}
	return (0);
}

/**
 * _strdup_ - creates copy of a string
 * @src1: the original string
 * Return: the copy of the string src1
 */
char *_strdup_(char *src1)
{
	int j;
	int rlen;
	char *det;

	rlen = _strlen(src1);
	det = malloc(sizeof(char) * (rlen + 1));

	for (j = 0; src1[j] != '\0'; j++)
		det[j] = src1[j];
	det[j] = '\0';
	return (det);
}

/**
 * *_strcat_ - concatenat two strings
 * @det: destination of
 * @src1: source of
 * Return: a ptr to the resulting str destination
 */

char *_strcat_(char *det, char *src1)
{
	char *ptn = det;

	while (*ptn != '\0')
	{
		ptn++;
	}
	while (*src1 != '\0')
	{
		*ptn++ = *src1++;
	}
	*ptn++ = '\0';
	return (det);
}


/**
 * _strcpy_ - copie string
 * @det: pointer
 * @src1: pointer too
 * Return: the ptr to dest
 */

char *_strcpy_(char *det, char *src1)
{
	int j, x;

	j = 0;
	while (src1[j])
		j++;

	for (x = 0; x <= j; x++)
	{
		det[x] = src1[x];
	}

	return (det);
}
