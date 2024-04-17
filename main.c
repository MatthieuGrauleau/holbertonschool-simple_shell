#include "main.h"

/**
 * main - entry point
 *
 * Return: 0 for success.
*/

int main(void)
{
	char *cmd;

	if (isatty(STDIN_FILENO) == 1)
	{
		while (1)
		{
			prompt();
			cmd = get_line();
			process(cmd);
			free(cmd);
		}

	}
	else
	{
		cmd = get_line();
		process(cmd);
		free(cmd);
	}
	return (0);
}
