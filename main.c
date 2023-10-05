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
	(void)ac;
	(void)av;

	if (ac >= 2)
	{
		/* run shell in non interactive mode*/
	}
	else
	{
		interactive_shell();
	}
	return (EXIT_SUCCESS);
}
