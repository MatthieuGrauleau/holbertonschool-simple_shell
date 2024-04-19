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
		printf("%s\n", environ[i]);
	}
}