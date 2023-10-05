#include "../main.h"

int main()
{
	/* testing _putchar */
	_putchar('A');
	_putchar('\n');
	_putchar('X');
	_putchar('\n');

	/* testing print_string */
	print_string("hello world\n");
	print_string("123456789\n");

	/* testing print_number */
	print_number((int)-999);
	_putchar('\n');
	print_number((long int)-999);
	_putchar('\n');

	/* testing print_unsigned_int */
	print_unsigned_int((unsigned int)-999);
	_putchar('\n');
	print_unsigned_int((unsigned long int)-999);
	_putchar('\n');

	/* end */
	return (1);
}
