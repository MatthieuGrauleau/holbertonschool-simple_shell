#include "main.h"

int main(void)
{
	char *line;

	if (isatty(STDIN_FILENO == 1))
	{
		do
		{
			prompt();
			line = get_line();
			process(line);
		} while (1);
	}
	return (0);
}