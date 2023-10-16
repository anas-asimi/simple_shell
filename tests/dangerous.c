/* DANGEROUS CODE */

#include <stdio.h>

int main(void)
{
	FILE *f;
	char *s;
	size_t n = 0;

	f = fopen("/dev/zero", "r");
	getline(&s, &n, f);

	return 0;
}
