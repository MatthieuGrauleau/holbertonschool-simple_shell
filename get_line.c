#include "main.h"

char *get_line(void)
{
	char *buff;
	size_t buff_size;
	
	if (getline(&buff, &buff_size, stdin) == -1)
	{
		if (feof(stdin) == 1)
		{
			printf("end of a file\n");
			exit(EXIT_SUCCESS);
		}
		printf("cannot read the stdin \n");
		exit(EXIT_FAILURE);
	}
	return (buff);
}