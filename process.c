#include "main.h"

int process(char *line)
{
 pid_t pid;

 char  *argv[2];
 argv[0] = line;
 argv[1] = NULL;

 pid = fork();

 if (pid == 0)
 {
	if(execve(line, argv, NULL) == -1)
	{
		perror("./hsh");
		exit(EXIT_FAILURE);
	}
	else if (pid > 0) 
	{
    wait(NULL);
	} 
	else 
	{
    perror("fork");
    exit(EXIT_FAILURE);
	}
 }
 return (0);
}