#include "../main.h"

int main()
{
	char *string;
	int i;

	while (1)
	{
		printf("#cisfun$ ");
		string = read_line();
		printf("string : %s\n", string);
	}
	return (0);
}
