#include "../main.h"

int main()
{
	char *string;
	char *result;
	char **array;

	/* testing _strsplit */
	string = "hello world its me";
	array = _strsplit(string, " ");

	result = _strconcat(array, " ");
	print_string(result);
	print_string("\n");
	result = _strconcat(array, "/");
	print_string(result);
	print_string("\n");

	return (0);
}
