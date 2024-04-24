#include "main.h"
/**
 * cd - function to change directory
 * @token: input from command
 * Return: 0 for success
 */
int cd(char **token)
{
	if (token[1] == NULL)
	{
		fprintf(stderr, "expected argument to \"cd\"\n");
	}
	else
	{
		if (chdir(token[1]) != 0)
		{
			perror("error in own_cd.c: changing dir\n");
		}
	}
	return (0);
}
