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
	int read;

	if (isatty(STDIN_FILENO))
	{
		prompt();
	}

	read = getline(&line, &line_size, stdin);

	if (read < 0)
	{
		free(line);
		return (NULL);
	}
	else if (read == 0)
	{
		return (0);
	}
	return (line);
}
