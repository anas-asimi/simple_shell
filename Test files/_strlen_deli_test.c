#include "../main.h"
#include "../_strings_functions.c"

int main()
{
	/* testing _strlen_deli */
	printf("%d\n",_strlen_deli("123456", ' '));
	printf("%d\n",_strlen_deli("123456 ", ' '));
	printf("%d\n",_strlen_deli("123 456 ", ' '));
	printf("%d\n",_strlen_deli("123 456 " + 1, ' '));

	/* end */
	return (1);
}
