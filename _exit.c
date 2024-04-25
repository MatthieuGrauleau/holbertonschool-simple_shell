#include "main.h"
/**
 * own_exit - exit program shell
 * @token: token from str_tok
 * Return: return 42
*/

int own_exit(char **token)
{
	/* exit with status */
	if (token[1])
	{
		return (atoi(token[1]));
	}
	/* exit success */
	else
	{
		return (42); /*Return 42 to signal to exit the shell*/
	}
}
