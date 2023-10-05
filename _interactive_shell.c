#include "main.h"

/**
 * interactive_shell - interactive_shell
 * Return: int
 */
int interactive_shell(void)
{
	char *commands_ptr;
	char *commands_ptr_copy;
	const char *delim = " ";
	size_t number_of_chars = 0;

	while (1)
	{
		print_string("#cisfun$ ");
		getline(&commands_ptr, &number_of_chars, stdin);
		if (number_of_chars == -1)
			return (-1);
		commands_ptr_copy = _strcpy(commands_ptr);
		print_string(commands_ptr_copy);
		free(commands_ptr_copy);
		free(commands_ptr);
	}
	return (0);
}
