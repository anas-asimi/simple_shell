#include "../main.h"

/**
 * main - entry point to the shell
 * Return: 0 on success, 1 on error
 */
int main()
{
	char *string;

	string = read_line();
	printf("string : %s\n", string);
	free(string);
	
	return (0);
}
