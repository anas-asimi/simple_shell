/* DANGEROUS CODE */
#include <stdio.h>

/**
 * main - entry point to the shell
 * Return: 0 on success, 1 on error
 */
int main(void)
{
	FILE *f;
	char *s;
	size_t n = 0;

	f = fopen("/dev/zero", "r");
	getline(&s, &n, f);

	return 0;
}
