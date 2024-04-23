#include "main.h"

int process(char **token, char **av, int path) {
    pid_t pid;
    int status, built;

    if (token[0] == NULL) {
        return 0;
    }

    built = built_in(token);
    if (built != 0) {
        return built;
    }
    handle_path(token, av, path);

    pid = fork();

    if (pid == 0) {
        if (execve(token[0], token, environ) == -1) {
            fprintf(stderr, "%s: %d: %s: not found\n", av[0], path, token[0]);
            free(token);
            exit(1);
        }
    } else {
        wait(&status);
        return status;
    }

    return 0;
}
