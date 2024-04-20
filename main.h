#ifndef MAIN_H
#define MAIN_H

extern char **environ;

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

void prompt(void);
char *get_line(void);
int process(char **tokens);
char **str_tok(char *line);
int main(void);
void env(char **environ);
char *read_stream(void);

#endif
