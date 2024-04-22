#include "main.h"

/**
 * process - function that process.
 *
 * @token: pointer to an array of string from str_tok.
 * @av: name of prorgam to print in stdou
 * @path: ID of program to print in stdou
 * Return: 0;
*/
int process(char **token, char **av, int path)
{
	pid_t pid;
	int status;
	char *phraze = "%s: %d: %s: not found\n";

	if (token[0] == NULL)
	{
		return (1);
	}
	if (built_in(token) != 0)
	{
		return (built_in(token));
	}

	pid = fork();

	if (pid == 0)
	{
		if (execve(token[0], token, environ) == -1)
		{
			fprintf(stderr, phraze, av[0], path, token[0]);
			free(token);
			exit(errno);
		}
	}

	else
	{
		wait(&status);
		return (status);
	}
	return (0);
}
