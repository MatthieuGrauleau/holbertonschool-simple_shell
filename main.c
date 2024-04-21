#include "main.h"

/**
 * main - entry point
 *
 * Return: 0 for success.
*/

int main(void)
{
	char *line = NULL;
	char **tokens;
	int status = 0;


	while (1)
	{
		errno = 0;

			line = get_line();
			if (line)
			{
				tokens = str_tok(line);
				status = process(tokens);
				free(tokens);
				free(line);
				if (status == 45)
				{
					return (0);
				}
			}
			else
			{
				if (isatty(STDIN_FILENO))
				{
					write(STDOUT_FILENO, "\n", 1);
				}
				exit(status);
			}

	}
	return (status);
}
