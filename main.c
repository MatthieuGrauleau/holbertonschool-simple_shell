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

	if (isatty(fileno(stdin)))
	{
		do
		{
			prompt();
			line = get_line();
			tokens = str_tok(line);
			status = process(tokens);		
			free(tokens);
			free(line);
			if (status > 0)
			{
				exit(status);
			}
		}  while (status == 0);

	}
	else
	{
		do
		{
			line = read_stream();
			tokens = str_tok(line);
			status = process(tokens);
			free(tokens);
			free(line);
			if (status > 0)
			{
				exit(status);
			}
		}  while (status == 0);
	}
	return (0);
}
