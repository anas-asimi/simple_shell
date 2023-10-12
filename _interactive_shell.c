#include "main.h"

/**
 * interactive_shell - interactive_shell
 * Return: int
 */
int interactive_shell(void)
{
	char *line;
	char **tokens;

	while (1)
	{
		print_string("#cisfun$ ");
		line = read_line();
		if (line == NULL)
			break;
		tokens = _strsplit(line, " ");
		print_string(tokens[0]);
	}
	return (0);
}
