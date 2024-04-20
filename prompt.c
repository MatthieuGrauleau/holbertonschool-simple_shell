#include "main.h"

/**
 * prompt - function that creates the prompt
*/
void prompt(void)
{
	write(STDOUT_FILENO, "$ ", 2);
}
