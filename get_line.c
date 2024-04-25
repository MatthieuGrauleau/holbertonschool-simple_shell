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
		prompt(); /*Display the shell prompt if in an interactive shell*/
	}

	if (getline(&line, &line_size, stdin) == -1)
	{
		free(line);
		return (NULL); /*Return NULL if EOF is reached or error occurs*/
	}
	return (line);
}
