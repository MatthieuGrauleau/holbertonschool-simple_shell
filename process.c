#include "main.h"

/**
 * process - function that process.
 *
 * @token: Pointer to an array of strings from str_tok.
 * @av: Name of program to print in stdout.
 * @path: ID of program to print in stdout.
 * Return: 0;
 */
int process(char **token, char **av, int path)
{
    pid_t pid;
    int status, built;
    char *phraze = "%s: %d: %s: not found\n";

    if (!token || !token[0])
        return (0);

    built = built_in(token);
    if (built != 0)
        return (built);

    pid = fork();
    if (pid == -1)
        return (1);

    if (pid == 0)
    {
        if (execve(token[0], token, environ) == -1)
        {
            if (handle_path(token, phraze, av, path) == 1)
            {
                free(token);
                exit(127);
            }
        }
    }
    else
    {
        wait(&status);
        return (status);
    }
    return (0);
}
