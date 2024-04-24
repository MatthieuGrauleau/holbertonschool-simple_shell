#include "main.h"

/**
 * get_line - function that get the line
 *
 * Return: the line.
*/
char *get_line(void)
{
	char *line = NULL;
	size_t line_size = 0;

	if (isatty(STDIN_FILENO))
	{
		prompt();
	}

	if (getline(&line, &line_size, stdin) == -1)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
