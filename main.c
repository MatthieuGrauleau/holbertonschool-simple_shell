#include "main.h"

/**
 * main - entry point
 * @av: arguments in the stdin
 * @ac: numbers of arguments
 *
 * Return: 0 for success.
*/

int main(int ac, char **av)
{
	char *line = NULL;
	char **tokens;
	int status = 0, pathnumb = 0;
	(void)ac;

	while (1)
	{
		errno = 0;
		line = get_line(); /*Read a line from stdin*/
		if (line == NULL && errno == 0)
			exit(1); /*Exit if EOF is reached or error occurs*/
		if (line)
		{
			pathnumb++;
			tokens = str_tok(line); /*Tokenize the input line*/
			if (tokens == NULL)
				free(line);
			status = process(tokens, av, pathnumb); /*Process the tokens*/
			free(tokens);
			free(line);
			if (status == 42)
				exit(0); /*Exit if 'exit' command is entered*/
		}
		else
		{
			if (isatty(STDIN_FILENO))/*Print a newline if in an interactive shell*/
				write(STDOUT_FILENO, "\n", 1);
			exit(status);
		}
	}
	exit(status);
}
