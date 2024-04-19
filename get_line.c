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

	read = getline(&line, &line_size, stdin);

	if (read == 0)
	{
		free(line);
		exit(EXIT_SUCCESS);
	}
	else if (read < 0)
	{
		free(line);
		exit(EXIT_FAILURE);
	}

	if (read > 0 && line[read - 1] == '\n')
	{
		line[read - 1] = '\0';
	}
	return (line);
}
