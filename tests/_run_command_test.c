#include "../main.h"

int main()
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
