#ifndef MAIN_H
#define MAIN_H

extern char **environ;

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

void prompt(void);
char *get_line(void);
void process(char *line);

#endif
