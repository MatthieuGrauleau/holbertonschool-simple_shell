#include"main.h"
/**
 * env - print the environment
 * @token: argument
 * Return: return 1 after function
*/
void env(void)
{
	int i = 0;

		while (environ[i] != NULL)
		{
			/*Print each environment variable*/
			printf("%s\n", environ[i]);
			i++;
		}
}
