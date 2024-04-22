#include"main.h"
/**
 * env - print the environment
 * @token: argument
 * Return: return 1 after function
*/
int env(char **token)
{
int i = 0;

(void)**token;


	while (environ[i])
	{
		write(STDOUT_FILENO, environ[i], strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}

return (0);
}
