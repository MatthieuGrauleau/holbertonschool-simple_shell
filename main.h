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

void prompt(void);
char *get_line(FILE *input_stream);
void process(char **tokens);
char **str_tok(char *line);

#endif
