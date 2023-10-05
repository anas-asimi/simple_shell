#include "main.h"

/**
 * interactive_shell - interactive_shell
 * Return: int
 */
int interactive_shell(void)
{
	char *commands_ptr;
	char **token;
	char delim = ' ';
	size_t number_of_chars = 0;

	while (1)
	{
		print_string("#cisfun$ ");
		getline(&commands_ptr, &number_of_chars, stdin);
		if (number_of_chars < 0)
			return (-1);
		token = _strsplit(commands_ptr, delim);
		print_string(token[0]);
	}
	return (0);
}
