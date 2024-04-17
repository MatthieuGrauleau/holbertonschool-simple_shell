#include "main.h"

void process(char *line)
{
	pid_t pid;
	int status;
	
	char *token;
	char *args[64];
	int i = 0;

	token = strtok(line, " \t\n");

	while (token != NULL)
	{
		args[i++] = token;
		token = strtok(NULL, " \t\n");
	}

	args[i] = NULL;

	pid = fork();

	if (pid == 0)
	{
		if (execve(args[0], args, __environ) == -1)
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
		wait(&status);
	}
}