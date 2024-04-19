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

	pid = fork();

	if (pid == 0)
	{
		if (execve(token[0], token, NULL) == -1)
		{
			perror("./hsh");
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		perror("fork");
	}
	else
	{
		waitpid(pid, NULL, 0);
	}
	return (-1);
}
