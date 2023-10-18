#include "../main.h"

/**
 * main - entry point to the shell
 * Return: 0 on success, 1 on error
 */
int main(void)
{
	int status;
	char *command;
	char **token;

	command = "whoami";
	printf("command is : %s\n", command);
	token = _strsplit("whoami", " ");
	status = _execute(token);
	printf("status : %d\n", status);
	return (0);
}
