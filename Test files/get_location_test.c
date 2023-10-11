#include "../main.h"
#include "../_shell_functions.c"
#include "../_strings_functions.c"

int main()
{
	char *string;

	/* testing _strsplit */
	string = get_location("gcc");
	printf("command is in : %s\n", string);

	return (1);
}
