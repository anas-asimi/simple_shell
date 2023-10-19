#include "main.h"

/**
 * main - is the main function that lance the program
 * @argc: is number of @argv
 * @d: is data
 * @argv: is an array of arguments
 * Return: Always 0.
 */
int main(int argc, char **argv)
{
	data dt;
	(void)argc;
	init_dt(&dt, argv[0]);
	_exe_cmnd(&dt);

	return (0);
}
