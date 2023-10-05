#include "../main.h"

int main()
{
	/* testing _strlen_deli */
	print_number(_strlen_deli("123456", ' '));
	_putchar('\n');
	print_number(_strlen_deli("123456 ", ' '));
	_putchar('\n');
	print_number(_strlen_deli("123 456 ", ' '));
	_putchar('\n');
	print_number(_strlen_deli("123 456 " + 1, ' '));
	_putchar('\n');

	/* end */
	return (1);
}
