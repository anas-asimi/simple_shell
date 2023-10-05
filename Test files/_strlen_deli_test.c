#include "../main.h"
#include "../_strings_functions.c"
#include "../_printing_functions.c"

int main()
{
	char *string;

	/* testing _strlen_deli */
	string = "123456";
	print_string(string);
	_putchar('\n');
	print_number(_strlen(string));
	_putchar('\n');
	print_number(_strlen_deli(string, ' '));
	_putchar('\n');

	/* end */
	return (1);
}
