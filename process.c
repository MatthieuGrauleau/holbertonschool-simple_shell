#include "main.h"

/**
 * process - function that process.
 *
 * @token: pointer to an array of string from str_tok.
 * Return: 1;
*/
int process(char **token)
{
	pid_t pid;
	int status;
	char **env = environ;

	pid = fork();

	if (pid == 0)
	{
		if (execve(token[0], token, env) == -1)
		{
			perror("./hsh");
			exit(EXIT_FAILURE);
		}
	}
	else if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else
	{
		if (waitpid(pid, &status, 0) == -1)
		{
			perror("waitpid");
			exit(EXIT_FAILURE);
		}
	}
	return (1);
}
