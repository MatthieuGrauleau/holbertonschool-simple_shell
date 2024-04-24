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
    char **env = environ;
    char *paths = NULL;

    if (token[0] == NULL)
    {
        return (0);
    }
    
    built = built_in(token);
    if (built != 0)
    {
        return (built);
    }

    while (*env != NULL)
    {
        if (strncmp(*env, "PATH=", 5) == 0)
        {
            paths = *env + 5;
            break;
        }
        env++;
    }
    pid = fork();
    if (pid == 0)
    {
        if (execve(token[0], token, environ) == -1)
        {
            if (paths != NULL)
            {
                paths = strtok(paths, ":");
                while (paths != NULL)
                {
                    char *full_path = malloc(strlen(paths) + 1 + strlen(token[0]) + 1);
                    if (full_path == NULL)
                    {
						free(full_path);
                        exit(1);
                    }
                    strcpy(full_path, paths);
                    strcat(full_path, "/");
                    strcat(full_path, token[0]);
                    if (access(full_path, X_OK) == 0)
                    {
                        if (execve(full_path, token, environ) == -1)
                        {
							free(full_path);
                            exit(1);
                        }
                    }
                    paths = strtok(NULL, ":");
                    free(full_path);
                }
            }

            fprintf(stderr, phraze, av[0], path, token[0]);
            free(token);
            exit(127);
        } else
		{
			exit(127);
		}
    }
    else
    {
        wait(&status);
        return (status);
    }
    return (0);
}
