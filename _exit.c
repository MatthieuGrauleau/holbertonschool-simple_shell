#include "main.h"
/**
 * _exit - exit program shell
 * @token: token from str_tok
 * Return: return 42
*/
int own_exit(char **token)
{
	(void)(**token);
	return (42);
}