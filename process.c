#include "main.h"

void process(char *line)
{
	pid_t pid;
	int status;
	char *args[2];

	args[0] = line;
	args[1] = NULL;

	pid = fork();

	if (pid == 0)
	{
		if (execve(line, args, NULL) == -1)
		{
			perror("./hsh");
			exit(EXIT_FAILURE);
		}
	} else if (pid == -1)
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
}
