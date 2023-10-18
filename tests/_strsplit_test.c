#include "../main.h"

/**
 * main - entry point to the shell
 * Return: 0 on success, 1 on error
 */
int main()
{
	char *string;
	char **array;
	int i;

	string = "hello world its me";
	array = _strsplit(string, " ");
	for (i = 0; array[i]; i++)
		printf("word is : [%s]\n", array[i]);

	free_array(array);
	return (0);
}
