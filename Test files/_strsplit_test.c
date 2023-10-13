#include "../main.h"

int main()
{
	char *string;
	char **array;
	int i;

	/* testing _strsplit */
	string = "123 456 \\ 789";
	array = _strsplit(string, " ");

	for (i = 0; array[i]; i++)
	{
		printf("string in index %d is	: %s\n", i, array[i]);
	}
	printf("string before is		: %s\n", string);
	string = "abc def \\ ghi";
	array = _strsplit(string, " ");
	printf("string after is			: %s\n", string);

	return (0);
}
