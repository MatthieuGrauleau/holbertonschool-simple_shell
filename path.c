#include "main.h"

void handle_path(char **token, char **av, int path) {
    char *paths = NULL;
    char **env = environ;

    while (*env != NULL) {
        if (strncmp(*env, "PATH=", 5) == 0) {
            paths = *env + 5;
            break;
        }
        env++;
    }

    if (paths != NULL) {
        paths = strtok(paths, ":");
        while (paths != NULL) {
            char *full_path = malloc(strlen(paths) + 1 + strlen(token[0]) + 1);
            if (full_path == NULL) {
                free(full_path);
                exit(1);
            }
            strcpy(full_path, paths);
            strcat(full_path, "/");
            strcat(full_path, token[0]);
            if (access(full_path, X_OK) == 0) {
                if (execve(full_path, token, environ) == -1) {
                    free(full_path);
                    exit(1);
                }
            }
            paths = strtok(NULL, ":");
            free(full_path);
        }
    }
    fprintf(stderr, "%s: %d: %s: not found\n", av[0], path, token[0]);
    free(token);
    exit(1);
}
