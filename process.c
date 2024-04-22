#include "main.h"

#define PATH_MAX 4096

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
	char *path_env = getenv("PATH");

	if (token[0] == NULL)
	{
		return (0);
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
			if (path_env != NULL)
			{
				char *paths = strtok(path_env, ":");
				while (paths != NULL)
				{
					char full_path[PATH_MAX];
					snprintf(full_path, sizeof(full_path), "%s/%s", paths, token[0]);
					if (access(full_path, X_OK) == 0)
					{
						if (execv(full_path, token) == -1)
						{
							exit(0);
						}
					}
					paths =strtok(NULL, ":");
				}
			}
			
			fprintf(stderr, phraze, av[0], path, token[0]);
			free(token);
			exit(0);
		}
	}

	else
	{
		wait(&status);
		return (status);
	}
	return (0);
}
