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
	int size = 0;
	size_t i = 0;

	if (line == NULL)
	{
		return (NULL);
	}
	/**
	if (line[0] == ' ')
	{
		for (i = 0; line[i]; i++)
		{
			if (line[i] == ' ')
			{
				size++;
			}
		}
	}
	if ((size + 1) == o_strlen(line))
	{
		return (NULL);
	}*/

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
