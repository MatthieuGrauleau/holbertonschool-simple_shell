#include "main.h"

/**
 * str_tok - function that split the line from get line in args
 * @line: array of char from get line
 * Return: the args
*/
char **str_tok(char *line)
{
	char *token;
	char **args;
	int size = 64;
	int i = 0;

	args = malloc(size * sizeof(char *));
	if (args == NULL)
	{
		fprintf(stderr, "problem allocation memory for token \n");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, " \t\n");

	while (token != NULL)
	{
		args[i] = token;
		i++;
		/**if (i >= size)
		{
			size += size;
			args = realloc(args, size * sizeof(char *));
			if (args == NULL)
			{
				fprintf(stderr, "problem allocation memory for args \n");
				exit(EXIT_FAILURE);
			}
		}*/
		token = strtok(NULL, " \t\n");
	}

	args[i] = NULL;
	return (args);
}
