#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(void) {
    char *buffer = NULL;
    size_t bufsize = 0;
    char *args[2];
    int status;

    while (1) {
        prompt();

        if (getline(&buffer, &bufsize, stdin) == -1) {
            break;
        }

        buffer[strcspn(buffer, "\n")] = '\0';

        args[0] = buffer;
        args[1] = NULL;

        if (fork() == 0) {
            if (execve(args[0], args, NULL) == -1) {
                perror("./hsh");
            }
            exit(EXIT_FAILURE);
        } else {
            wait(&status);
        }
    }

    free(buffer);

    return 0;
}
