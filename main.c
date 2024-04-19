#include "main.h"

/**
 * main - entry point
 *
 * Return: 0 for success.
*/

int main(void)
{
	char *line;
	char **tokens;

	if (isatty(STDIN_FILENO) == 1)
	{
		while (1)
		{
			prompt();
			line = get_line();
			tokens = str_tok(line);
			process(tokens);
			free(tokens);
			free(line);
		}

	}
	else
	{
		while (1)
		{
			line = get_line();
			tokens = str_tok(line);
			process(tokens);
			free(tokens);
			free(line);
		}
	}
	return (0);
}
