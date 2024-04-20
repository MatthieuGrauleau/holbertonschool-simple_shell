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
			tokens = str_tok(line);
			status = process(tokens);		
			free(tokens);
			free(line);
			if (status == 200)
			{
				return (0);
			}
	}

	/**else
	{
		do
		{
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
	}*/
	return (status);
}
