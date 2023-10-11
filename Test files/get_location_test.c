#include "../main.h"
#include "../_shell_functions.c"
#include "../_strings_functions.c"

int main()
{
	char *string;

	/* testing _strsplit */
	string = get_location("gcc");
	if (string == NULL)
	{
		printf("command not found");
	}
	
	printf("command is : %s\n", string);

	return (1);
}
