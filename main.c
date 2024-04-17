#include "main.h"

int main(void)
{
	char *line;

	if (isatty(STDIN_FILENO) == 1)
	{
		while (1)
		{
			prompt();
			line = get_line();
			process(line);
		}

	}
	else 
	{
		line = get_line();
		process(line);	
	}

	return (0);
}
