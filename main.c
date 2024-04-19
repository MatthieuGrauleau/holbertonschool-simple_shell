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
	int status = 0;

	if (isatty(STDIN_FILENO) == 1)
	{
		do
		{
			prompt();
			line = get_line();
			tokens = str_tok(line);
			status = process(tokens);
			if (status == -1)
			{
				exit(status);
			}
			free(tokens);
			free(line);
		}  while (status == 0);

	}
	else
	{
		do
		{
			line = get_line();
			tokens = str_tok(line);
			status = process(tokens);
			if (status == -1)
			{
				exit(status);
			}
			free(tokens);
			free(line);
		}  while (status == 0);
	}
	return (0);
}
