#include "main.h"

/**
 * main - entry point
 * @ac: arg count
 * @av: arg vector
 *
 * Return: 0 on success, 1 on error
 */
int main(int ac, char **av)
{
	int status;
	char *line;
	char **tokens;

	(void)ac;

	if (ac >= 2)
	{
		/* run shell in non interactive mode*/
		status = run_command(av + 1);
		if (status == 1)
			print_err(av[0], av[1]);
	}
	else
	{
		while (1)
		{
			print_string("#cisfun$ ");
			line = read_line();
			if (line == NULL)
				break;

			tokens = _strsplit(line, " ");
			status = run_command(tokens);
			if (status == 1)
				print_err(av[0], tokens[0]);
			free(line);
		}
	}
	_putchar('\n');
	return (status);
}
