#include "../main.h"

int main()
{
	char *string;

	/* testing _strsplit */
	string = _get_location("gcc");
	if (string == NULL)
		printf("command not found");
	printf("command is : %s\n", string);
	return (1);
}
