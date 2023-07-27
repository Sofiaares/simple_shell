#include "shell.h"

/**
 * read_line - read a line from terminal
 * Return: pointer which points to a str with the line content
 */

char *read_line(void)
{
	char *rline = NULL;
	size_t bxf_size = 0;

	if (getline(&rline, &bxf_size, stdin) == -1) /* if getline fails */
	{
		_puts("\n");
		free(rline);
		exit(EXIT_FAILURE);
	}
	return (rline);
}

/**
 * count_token - countof token in put.
 * @rline: the string input to split
 * @ydlmt: delimiter specify where to cut the input
 * Return: number of tokens.
 */

int count_token(char *rline, const char *ydlmt)
{
	char *linecop;
	char *tokens;
	int j;

	linecop = _strdup_(rline);
	if (linecop == NULL)
		return (-1);
	tokens = strtok(linecop, ydlmt);
	for (j = 0; tokens != NULL; j++)
		tokens = strtok(NULL, ydlmt);
	free(linecop);
	return (j);
}

/**
 * parse_line - in put from the user and make an array of strings
 * @in_put: the command line input
 * @delimi: separater where strtok can split the string
 * Return: an array of strings parsed from command line input.
 */

char **parse_line(char *in_put, const char *delimi)
{
	char **commandarr;
	char *tokens;
	char *inputcop;
	int t_counts;
	int j = 0;

	t_counts = count_token(in_put, delimi);
	if (t_counts == -1)
	{
		free(in_put);
		exit(1);
	}
	if (in_put == NULL)
		return (NULL);
	inputcop = _strdup_(in_put);

	if (inputcop == NULL)
		return (NULL);
	commandarr = malloc((t_counts + 1) * sizeof(char *));
	if (!commandarr)
	{
		free(in_put);
		perror("Alloc fails");
		exit(EXIT_FAILURE);
	}

	tokens = strtok(inputcop, delimi);
	while (tokens)
	{
		if (tokens[0] == '#')
			break;
		commandarr[j] = _strdup_(tokens);
		tokens = strtok(NULL, delimi);
		j++;
	}
	commandarr[j] = NULL;
	free(inputcop);
	return (commandarr);
}
