#include "main.h"

/**
 * handle_path - Find and handle the full path of the program.
 *
 * @token: Pointer to an array of strings from str_tok.
 * @phraze: Error message format.
 * @av: Name of the program to print in stderr.
 * @path: ID of program to print in stderr.
 * Return: 0 on success, 1 on failure.
 */
int handle_path(char **token, char *phraze, char **av, int path)
{
	char *paths = NULL;
	char *full_path;
	char *path_token;
	/*Iterate through the environment variables to find the PATH variable*/
	while (*environ != NULL)
	{
		if (strncmp(*environ, "PATH=", 5) == 0)
		{
			paths = *environ + 5; /*Set paths to the value of PATH*/
			break;
		}
		environ++;
	}
	if (!paths)
		return (1);
		/*Tokenize the PATH variable to iterate through each path*/
	path_token = strtok(paths, ":");
	while (path_token != NULL)
	{	/*Construct the full path by concat the path token and the program name*/
		full_path = malloc(strlen(path_token) + 1 + strlen(token[0]) + 1);
		if (!full_path)
			return (1);
		strcpy(full_path, path_token);
		strcat(full_path, "/");
		strcat(full_path, token[0]);
		if (access(full_path, X_OK) == 0) /*Check if the full path is executable*/
		{	/*Execute the program with the full path*/
			if (execve(full_path, token, environ) == -1)
			{
				free(full_path);
				return (1);
			}
		}
		free(full_path);
		path_token = strtok(NULL, ":");
	}
	fprintf(stderr, phraze, av[0], path, token[0]);
	return (1);
}
