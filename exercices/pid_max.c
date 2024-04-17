#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>

#define MAX_LINE 1024

/**
 * PID_MAX - Numbers of process max can be used by the program.
 * @fd: atribute in file directory and open the source
 * @argc: size and numbers of process read/write or read/only.
 * Return: (SUCCESS)
 */

int main(int argc, char *argv[])
{
        int fd;
        char line[MAX_LINE];
        ssize_t n;

        fd = open("/proc/sys/kernel/pid_max", (argc > 1) ? O_RDWR : O_RDONLY);
        if (fd == -1)
        {
                perror("Erreur d'ouverture du fichier");
                exit(EXIT_FAILURE);
        }

        n = read(fd, line, MAX_LINE);
        if (n == -1)
        {
                perror("Erreur de lecture du fichier");
                exit(EXIT_FAILURE);
        }

        if (argc > 1)
                printf("Ancienne valeur : ");
        printf("%.*s", (int)n, line);

        if (argc > 1)
        {
                if (lseek(fd, 0, SEEK_SET) == -1)
                {
                        perror("Erreur de lseek");
                        exit(EXIT_FAILURE);
                }

                if (write(fd, argv[1], strlen(argv[1])) != strlen(argv[1]))
                {
                        fprintf(stderr, "L'écriture a échoué\n");
                        exit(EXIT_FAILURE);
                }

                lseek(fd, 0, SEEK_SET);
                n = read(fd, line, MAX_LINE);
                if (n == -1)
                {
                        perror("Erreur de lecture du fichier");
                        exit(EXIT_FAILURE);
                }
                printf("/proc/sys/kernel/pid_max contient maintenant %.*s", (int)n, line);
        }

        close(fd);
        return EXIT_SUCCESS;
}
