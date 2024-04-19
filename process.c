#include "main.h"

/**
 * process - function that process.
 *
 * @token: pointer to an array of string from str_tok.
 * Return: 0;
*/
int process(char **token)
{
	pid_t pid;

	if (token == NULL)
	{
		return (0);
	}
	if ((strcmp(token[0], "env") == 0) && token[1] == NULL)
	{
		env(environ);
	}

	pid = fork();

	if (pid < 0)
	{
		perror("fork");
	}

	else if (pid == 0)
	{
		if (execve(token[0], token, environ) == -1)
		{
			perror("./hsh");
		}
		exit(EXIT_FAILURE);
	}
	
	else
	{
		wait(&status);
	}
	return (0);
}
