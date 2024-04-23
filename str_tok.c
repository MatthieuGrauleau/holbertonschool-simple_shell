#include "main.h"

/**
 * str_tok - function that split the line from get line in args
 * @line: array of char from get line
 * Return: the args
*/
char **str_tok(char *line)
{
	char *token = NULL;
	char **args = NULL;
	int size = 64;
	int i = 0;

	if (line == NULL)
	{
		return (NULL);
	}
	
	args = malloc((size + 2) * sizeof(char *));
	if (args == NULL)
		return (NULL);

	token = strtok(line, " \r\t\n");

	while (token != NULL)
	{
		args[i] = token;
		i++;
		if (i >= size)
		{
			size += size;
			args = realloc(args, size * sizeof(char *));
			if (args == NULL)
				return (NULL);
		}
		token = strtok(NULL, " \t\r\n");
	}

	args[i] = NULL;
	return (args);
}
