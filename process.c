#include "main.h"

/**
 * process - functiont that process.
 *
 * @line: string.
*/
void process(char *line)
{
	pid_t pid;
	int status;
	char *args[2];

	args[0] = line;
	args[1] = NULL;
	
	/**char *token;
	char *args[64];
	int i = 0;*/

	/**token = strtok(line, " \t\n");

	while (token != NULL)
	{
		args[i++] = token;
		token = strtok(NULL, " \t\n");
	}

	args[i] = NULL;*/

	pid = fork();

	if (pid == 0)
	{
		if (execve(args[0], args, NULL) == -1)
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
}
