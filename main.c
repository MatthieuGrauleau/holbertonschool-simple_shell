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
	int status = -1;

	if (isatty(STDIN_FILENO) == 1)
	{
		do
		{
			prompt();
			line = get_line();
			tokens = str_tok(line);
			status = process(tokens);		
			free(tokens);
			free(line);
			if (status >= 0)
			{
				exit(status);
			}
		}  while (status == -1);

	}
	else
	{
		do
		{
			line = get_line();
			tokens = str_tok(line);
			status = process(tokens);
			free(tokens);
			free(line);
			if (status >= 0)
			{
				exit(status);
			}
		}  while (status == -1);
	}
	return (0);
}
