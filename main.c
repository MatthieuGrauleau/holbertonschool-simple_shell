#include "main.h"

/**
 * main - entry point
 *
 * Return: 0 for success.
*/

int main(void)
{
	char *line;

	if (isatty(STDIN_FILENO) == 1)
	{
		while (1)
		{
			prompt();
			line = get_line();
			str_tok(line);
		}
	}
	return (0);
}
