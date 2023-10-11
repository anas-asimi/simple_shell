#include "../main.h"
#include "../_strings_functions.c"
#include "../_printing_functions.c"

int main()
{
	char *string;
	char *result;
	char **array;
	int i = 0;

	/* testing _strsplit */
	string = "hello world its me";
	array = _strsplit(string, " ");

	result = _strconcat(array, " ");
	print_string(result);
	print_string("\n");
	result = _strconcat(array, "/");
	print_string(result);

	return (1);
}
