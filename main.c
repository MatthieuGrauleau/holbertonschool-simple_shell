#include "main.h"

int main(void)
{
	if(isatty(STDIN_FILENO) == 1)
	{
		while (1)
		{
			prompt();
			get_line();
		}

	}

	return (0);
}