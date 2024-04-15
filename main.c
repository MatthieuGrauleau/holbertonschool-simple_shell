#include "main.h"

int main (void)
{
	if (isatty(STDIN_FILENO) == 1)
	{
		prompt();
	}

	return (0);
}