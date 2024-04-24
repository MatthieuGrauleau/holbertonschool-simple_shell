#include "main.h"
/**
 * own_exit - exit program shell
 * @token: token from str_tok
 * Return: return 42
*/

int own_exit(char **token)
{
	if (*token)
	{
	exit(2);
	}
return (0);
}
