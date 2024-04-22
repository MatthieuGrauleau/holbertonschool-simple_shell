#include "main.h"
/**
 * o_strlen - calculate the lenght in int
 * @line: line inpout
 * Return: size in int
*/
int o_strlen(char *line)
{
	int i;

	for (i = 0; line[i] != 0; i++)
		;

	return (i);
}
