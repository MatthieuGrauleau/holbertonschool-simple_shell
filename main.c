#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - entry point
 *
 * Return: 0 for success.
*/

int main(void)
{
	char *line;
	char **tokens;
	FILE *input_stream;

	if (isatty(STDIN_FILENO) == 1)
	{
		input_stream = stdin;
	}
	else
	{
		input_stream = stdin;
	}

	while ((line = get_line(input_stream)) != NULL)
	{
		tokens = str_tok(line);
		process(tokens);
		free(tokens);
		free(line);

		if (input_stream != stdin)
		{
			break;
		}
	}

	return (0);
}
