#include "../main.h"

int main()
{
	char *string;
	char **array;
	int i;

	/* testing _strsplit */
	string = "hello anas";
	array = _strsplit(string, " ");

	for (i = 0; array[i]; i++)
	{
		printf("pointer in index %d is	: %p\n", i, array[i]);
		printf("string in index %d is	: %s\n", i, array[i]);
	}
	array = _strsplit(string, " ");
	array = _strsplit(string, " ");
	array = _strsplit(string, " ");
	array = _strsplit(string, " ");
	array = _strsplit(string, " ");
	array = _strsplit(string, " ");
	printf("string is		: %s\n", string);
	return (1);
}
