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
	int status, built;
	char *phraze = "%s: %d: %s: not found\n";



	if (token[0] == NULL)
	{
		return (1);
	}

	built = built_in(token);
	if (built != 0)
	{
		return (built);
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
