#include "main.h"

/**
 *  built_in - check if there is a built in function according to arg[0]
 * @token: token from str_tok
 *
 * Return: 1 on sucess, 0 otherwise
 */
int built_in(char **token)
{
	char *builtin_func_list[] = {
		"env",
		"exit",
		"^D"
	};
	int (*builtin_func[])(char **) = {
		&env,
		&own_exit,
		&ctrld
	};
	unsigned long int i = 0;

	for (; i < sizeof(builtin_func_list) / sizeof(char *); i++)
	{
		if (strcmp(token[0], builtin_func_list[i]) == 0)
		{
			/*Call the corresponding built-in function*/
			return ((*builtin_func[i])(token));
		}
	}
	return (0);
}
