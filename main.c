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

	(void)ac;
	(void)av;

	if (ac >= 2)
	{
		/* run shell in non interactive mode*/
		command = _strconcat(av + 1, " ");
		print_string("command is : ");
		print_string(command);
		print_string("\n");
		status = 1;
	}
	else
	{
		status = interactive_shell();
	}
	return (status);
}
