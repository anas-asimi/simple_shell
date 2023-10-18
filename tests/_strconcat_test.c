#include "../main.h"

/**
 * main - entry point to the shell
 * Return: 0 on success, 1 on error
 */
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
