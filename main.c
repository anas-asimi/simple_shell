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
	if (isatty(STDIN_FILENO)) /* shell is running in interactive mode*/
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
				print_error(av[0], tokens[0]);
		}
	}
	else /* shell is running in non interactive mode*/
	{
		printf("ac is : %d\n", ac);
		printf("av[1] is : %s\n", av[0]);
		return (0);
		status = run_command(av + 1);
		if (status == 1)
			print_error(av[0], av[1]);
	}
	_putchar('\n');
	return (status);
}
