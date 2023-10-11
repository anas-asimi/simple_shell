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

	if (ac >= 2)
	{
		/* run shell in non interactive mode*/
		command = _strconcat(av + 1, " ");
		printf("command is : %s\n", command);
		status = 1;
	}
	else
		status = interactive_shell();
	return (status);
}
