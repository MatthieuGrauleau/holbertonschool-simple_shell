#include "main.h"

/**
 * str_tok - function that split the line from get line in tokens
 * @line: array of char from get line
 * Return: the tokens
*/
char **str_tok(char *line)
{
	char *token;
	char **tokens;
	int size = 64;
	int i = 0;

	tokens = malloc(size * sizeof(char *));
	if (tokens == NULL)
	{
		fprintf(stderr, "problem allocation memory for token \n");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, " \t\n");

	while (token != NULL)
	{
		tokens[i] = token;
		i++;
		if (i >= size)
		{
			size += size;
			tokens = realloc(tokens, size * sizeof(char *));
			if (tokens == NULL)
			{
				fprintf(stderr, "problem allocation memory for tokens \n");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, " \t\n");
	}

	tokens[i] = NULL;
	return (tokens);
}
