#include"main.h"
/**
 * env - print the environment
 * @environ: environment from parents
 *
*/
void env(char **environ)
{
int i = 0;

	while (environ[i])
	{
		write(STDOUT_FILENO, environ[i], strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}
