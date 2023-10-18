#include "../main.h"

/**
 * main - entry point to the shell
 * Return: 0 on success, 1 on error
 */
int main(void)
{
	char *line;
	while (1)
	{
		line = readFromStdin();
		printf("line after is : %s\n", line);
	}
	return (0);
}
