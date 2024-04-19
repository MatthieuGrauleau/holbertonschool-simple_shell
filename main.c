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
		}
	}
	while (1)
	{
		line = get_line();
		tokens = str_tok(line);
		process(tokens);
	}
	return (0);
}
