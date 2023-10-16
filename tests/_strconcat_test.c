#include "../main.h"

int main()
{
	char *array[4];
	char *string;
	int i;

	array[0] = "hello";
	array[1] = "world";
	array[2] = "Again!";
	array[3] = NULL;

	string = _strconcat(array, " ");
	printf("string is : [%s]\n", string);

	free(string);

	return (0);
}
