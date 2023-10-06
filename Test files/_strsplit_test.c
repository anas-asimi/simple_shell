#include "../main.h"
#include "../_strings_functions.c"

int main()
{
	char *string;
	char **array;
	int i;

	/* testing _strsplit */
	string = "hello world its me";
	array = _strsplit(string, ' ');

	for (i = 0; i < 5; i++)
	{
		printf("pointer in index %d is	: %p\n", i, array[i]);
		printf("string in index %d is	: %s\n", i, array[i]);
	}
	/* end */
	return (1);
}
