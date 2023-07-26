#include "shell.h"

/**
 * you_readline_i - it reads a line from a terminal
 * Return: pointer points to a str with content
 */

char *you_readline_i(void)
{
	char *rline_i = NULL;
	size_t buxsizze = 0;

	if (getline(&rline, &buxsizze, xstdin_i) == -1) /* if getline fail */
	{
		_puts_i("\n");
		free_i(line);
		exit(exit_failure);
	}
	return (rline);
}

/**
 * ct_tken_i - it takes tokens and given in put.
 * @rline: string to split input
 * @dlmtoho: to delimit and cut the input specify
 * Return: the number of token.
 */

int ct_tken_i(char *rline, const char *dlmtoho)
{
	char *rline_cp;
	char *tken;
	int j;

	rline_cp = _strd_up_i(rline);
	if (rline_cp == NULL)
		return (-1);
	tken = strtok(rline_cp, dlmtoho);
	for (j = 0; tken != NULL; j++)
		tken = strtok(NULL, dlmtoho);
	free_i(rline_cp);
	return (j);
}

/**
 * prase_yline_i - input from the utilis and it makes array of string
 * @inputin: the command to line in put
 * @ydelimit:  put where a seperation str tok that the string can splited
 * Return: parsed an array of strings from command line.
 */

char **prase_yline_i(char *inputin, const char *ydelimit)
{
	char **comnd_arri;
	char *tken;
	char *input_i;
	int s_count_i;
	int j = 0;

	s_count = count_tken_i(inputin, ydelimit);
	if (s_count_i == -1)
	{
		free_i(inputin);
		exit(1);
	}
	if (inputin == NULL)
		return (NULL);
	input_i = _strd_up_i(inputin);

	if (input_i == NULL)
		return (NULL);
	comnd_arri = malloc((s_count_i + 1) * sizeof(char *));
	if (!comnd_arri)
	{
		free_i(inputin);
		perror("Alloc fails");
		exit(exit_failure);
	}

	tken = str_tok_i(input_i, ydelimit);
	while (tken)
	{
		if (tken[0] == '#')
			break;
		comnd_arri[j] = _strd_up_i(tken);
		tken = str_tok_i(NULL, ydelimit);
		j++;
	}
	comnd_arri[j] = NULL;
	free_i(input_i);
	return (comnd_arri);
}
