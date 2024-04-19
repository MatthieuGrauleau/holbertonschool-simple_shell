#include "main.h"

/**
 * get_line - function that get the line
 *
 * @input_stream: to get interactif mode or not
 *
 * Return: the line.
*/
char *get_line(FILE *input_stream)
{
	char *line = NULL;
	size_t line_size = 0;

	if (getline(&line, &line_size, input_stream) == -1)
	{
		if (feof(input_stream))
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
