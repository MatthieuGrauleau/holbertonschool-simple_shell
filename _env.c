#include"main.h"
/**
 * env - print the environment
 * @token: argument
 * Return: return 1 after function
*/
int env(char **token)
{
	int i = 0;

	if (*token)
	{
	while (environ[i] != NULL) {
        printf("%s\n", environ[i]);
        i++;
    }
	}
	return (0);
}
