#include "main.h"

/**
 * main - entry point
 *
 * Return: 0 for success.
*/

int main(void)
{
	/**char *line;
	char **tokens;
	int status = 0;*/

	if (isatty(STDIN_FILENO) == 1)
	{
		while (1)
		{
			prompt();
		}
	}
	return (0);
}
