#include "main.h"

/**
 * main - entry point
 * @av: arguments in the stdin
 * @ac: numbers of arguments
 *
 * Return: 0 for success.
*/

int main(int ac, char **av, char **env)
{
	char *line = NULL;
	char **tokens;
	int status = 0, pathnumb = 0, path = 0;
	(void)ac;


	while (1)
	{
		errno = 0;

		line = get_line();
		if (line == NULL && errno == 0)
		{
			exit(1);
		}
			if (line)
			{
				pathnumb++;
				tokens = str_tok(line);
				if(tokens == NULL)
					free(line);
				path = values_path(&tokens[0], env);
				status = process(tokens, av, pathnumb, path);
				free(line);
				if (status == 42)
				{
					exit(0);
				}
				free(tokens);
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
	exit(status);
}
