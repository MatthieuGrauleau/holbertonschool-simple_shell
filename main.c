#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(void) {
    char buffer[BUFFER_SIZE];
    char *args[2];
    int status;

    while (1) {
        printf("$ ");
        fflush(stdout);

        if (fgets(buffer, BUFFER_SIZE, stdin) == NULL) {
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

    return 0;
}
