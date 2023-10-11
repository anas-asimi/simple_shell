#include "../main.h"
#include "../_strings_functions.c"
#include "../_printing_functions.c"

int main(int ac, char **av)
{
	char *string;

	(void)ac;
	string = _strconcat(av + 1, " ");
	printf("string : %s\n", string);
	return (1);
}
