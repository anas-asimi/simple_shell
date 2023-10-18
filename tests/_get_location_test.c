#include "../main.h"

/**
 * main - entry point to the shell
 * Return: 0 on success, 1 on error
 */
int main(void)
{
	char *command;
	char *location;

	command = "make";
	location = _get_location(command);
	if (command == NULL)
		printf("command not found");
	printf("command is : %s\n", command);
	printf("location is : %s\n", location);
	return (0);
}
