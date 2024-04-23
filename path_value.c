
#include "main.h"
/**
 * values_path - Separate the path in new strings.
 * @tokens: tokens from strtok
 * @env: Enviroment.
 * Return: Pointer to strings.
 */
int values_path(char **tokens, char **env)
{
	char *path = NULL;
	char *paths = NULL;
	struct stat stat_line;
	char *full_path = NULL;

if (stat(*tokens, &stat_line) == 0)
		exit(1);

 while (*env != NULL)
    {
        if (strncmp(*env, "PATH=", 5) == 0)
        {
            path = *env + 5;
            break;
        }
        env++;
    }
	if (path == NULL)
		return(-1);

	paths = strtok(path, ":");	
	full_path = malloc(strlen(paths) + 1 + strlen(tokens[0]) + 1);
	if (full_path == NULL)
	{
		return (-1);
	}
    while (paths != NULL)
    {
	
		strcpy(full_path, paths);
		strcat(full_path, "/");
		strcat(full_path, tokens[0]);
		if (stat(full_path, &stat_line) == 0)
		{
			*tokens = full_path;
			return (0);
		}
		paths = strtok(NULL, ":");

    }
	free(full_path);
	paths = '\0';
	return (-1);

}
