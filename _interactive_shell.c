#include "main.h"

/**
 * interactive_shell - interactive_shell
 * Return: none
 */
void interactive_shell()
{
	char *commands_ptr;
	size_t n = 0;

	while (1)
	{
		print_string("#cisfun$ ");
		getline(&commands_ptr, &n, stdin);
		print_string(commands_ptr);
	}
}
