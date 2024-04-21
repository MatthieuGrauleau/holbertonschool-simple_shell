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
	int status;

	if (token[0] == NULL)
	{
		return (1);
	}
	if ((strcmp(token[0], "env") == 0))
	{
		env(environ);
	}

	pid = fork();

	if (pid == 0)
	{
		if (execve(token[0], token, environ) == -1)
		{
			perror("./hsh");
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
