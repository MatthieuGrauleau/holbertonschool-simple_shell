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

    if (paths != NULL)
    {
        paths = strtok(paths, ":");
        while (paths != NULL)
        {
            size_t full_path_len = strlen(paths) + 1 + strlen(token[0]) + 1;
            char *full_path = malloc(full_path_len);
            if (full_path == NULL)
            {
                perror("malloc");
                exit(1);
            }
            strcpy(full_path, paths);
            strcat(full_path, "/");
            strcat(full_path, token[0]);
            if (access(full_path, X_OK) == 0)
            {
                pid = fork();
                if (pid == 0)
                {
                    if (execve(full_path, token, environ) == -1)
                    {
                        exit(1);
                    }
                }
                else if (pid < 0)
                {
                    perror("fork");
                    exit(1);
                }
                else
                {
                    wait(&status);
                    return (status);
                }
            }
            free(full_path);
            paths = strtok(NULL, ":");
        }
    }

    fprintf(stderr, phraze, av[0], path, token[0]);
    free(token);
    return (1);
}
