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

	if (getline(&line, &line_size, stdin) == -1)
	{
		if (feof(stdin))
		{
			free(line);
			exit(EXIT_SUCCESS);
		}
		else
		{
			free(line);
			exit(EXIT_FAILURE);
		}
	}
	return (line);
}