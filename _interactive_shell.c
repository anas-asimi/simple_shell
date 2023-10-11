#include "main.h"

/**
 * interactive_shell - interactive_shell
 * Return: int
 */
int interactive_shell(void)
{
	char *commands_ptr;
	char **array_of_strings;
	size_t number_of_chars, n;

	n = 0;
	while (1)
	{
		print_string("#cisfun$ ");
		number_of_chars = getline(&commands_ptr, &n, stdin);
		if (number_of_chars == -1)
			return (-1);
		array_of_strings = _strsplit(commands_ptr, " ");
		printf("number_of_chars : %ld\n", number_of_chars);
	}
	return (0);
}
