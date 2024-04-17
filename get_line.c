#include "main.h"

char *get_line(void)
{
	char *buff = NULL;
	size_t buff_size = 0;

	if (getline(&buff, &buff_size, stdin) == -1)
	{
		if (feof(stdin))
		{
			printf("End of a file\n");
			free(buff);
			exit(EXIT_SUCCESS);
		}
		else
		{
			printf("error");
			free(buff);
			exit(EXIT_FAILURE);
		}
	}
	return (buff);
}