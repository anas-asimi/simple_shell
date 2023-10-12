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
	char *command;
	char *line;
	char **tokens;

	(void)ac;

	if (ac >= 2)
	{
		/* run shell in non interactive mode*/
		command = _strconcat(av + 1, " ");
		(void)command;
		print_err_1(av[0], av[1]);
		status = 1;
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
			print_string(tokens[0]);
			free(line);
		}
	}
	return (status);
}
