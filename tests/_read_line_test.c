#include "../main.h"

int main()
{
	char *string;

	string = read_line();
	printf("string : %s\n", string);
	free(string);
	
	return (0);
}
