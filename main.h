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
#include <limits.h>

void prompt(void);
char *get_line(void);
int process(char **token, char **av, int path);
char **str_tok(char *line);
int main(int ac, char **av);
int built_in(char **token);

/*built in function*/
int env(char **token);
int ctrld(char **token);
int own_exit(char **token);
int o_strlen(char *line);

#endif
