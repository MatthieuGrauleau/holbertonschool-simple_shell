#ifndef MAIN_H
#define MAIN_H

extern char **environ;

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

void prompt(void);
char *get_line(void);
void process(char *line);

#endif
