#include "main.h"

char *get_line(void)
{
	char *line = NULL;
	size_t line_size = 0;

	if (getline(&line, &line_size, stdin) == -1)
	{
		if (feof(stdin))
		{
			printf("End of a file\n");
			exit(EXIT_SUCCESS);
		}
		else
		{
			printf("error");
			exit(EXIT_FAILURE);
		}
	}
	return (line);
}
