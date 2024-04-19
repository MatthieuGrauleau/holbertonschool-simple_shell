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

    pid = fork();

    if (pid == -1)
    {
        perror("fork");
        return -1;
    }
    else if (pid == 0)
    {
        if (execve(token[0], token, NULL) == -1)
        {
            perror("./hsh");
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        if (waitpid(pid, &status, 0) == -1)
        {
            perror("waitpid");
            return -1;
        }

        if (WIFEXITED(status))
        {
            int exit_status = WEXITSTATUS(status);
            if (exit_status != 0)
            {
                printf("Child process exited with status %d\n", exit_status);
            }
        }
        else if (WIFSIGNALED(status))
        {
            int signal_number = WTERMSIG(status);
            printf("Child process terminated by signal %d\n", signal_number);
        }
    }
    return 0;
}
