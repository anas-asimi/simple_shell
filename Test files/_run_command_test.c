#include "../main.h"

int main()
{
	int status;
	char *string;
	char **token;

	string = "gcc --version";
	token = _strsplit(string, " ");
	printf("command : %s\n", token[0]);
	status = run_command(token);
	printf("status : %d\n", status);
	return (1);
}
