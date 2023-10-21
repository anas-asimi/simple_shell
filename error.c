#include "main.h"

/**
 * _prt_error - function that error print to stderr
 * @sr1: name of shell program
 * @sr2: the error message
 * Return: void
 */
void _prt_error(const char *sr1, const char *sr2)
{
	if (!sr1 || !sr2)
		return;

	while (*sr1)
	{
		write(STDERR_FILENO, sr1, 1);
		sr1++;
	}

	write(STDERR_FILENO, ": ", 2);

	while (*sr2)
	{
		write(STDERR_FILENO, sr2, 1);
		sr2++;
	}
	write(STDERR_FILENO, "\n", 1);
}

/**
 * _trim_strg - is the function that trim a string with spces or tabs
 * @strg: the string to trim
 * Return: void.
 */

void _trim_strg(char *strg)
{
	int i, j, len = _strg_len(strg);

	for (i = 0; i < len && (strg[i] == ' ' || strg[i] == '\t'); i++)
		;

	for (j = 0; i < len; i++, j++)
		strg[j] = strg[i];

	strg[j] = '\0';

	for (i = _strg_len(strg) - 1;; i--)
	{
		if (i > 0 && (strg[i] == ' ' || strg[i] == '\t'))
			break;
		strg[i] = '\0';
	}
}

/**
 * _fuc_realloc - is my function of realloc
 * @n_size: unsigned int
 * @pot: is a pointer
 * Return: return the new memory
 */
void *_fuc_realloc(void *pot, unsigned int n_size)
{
	char *p;
	unsigned int i, tp = n_size, old_size = sizeof(pot);

	if (old_size == n_size)
		return (pot);
	if (pot == NULL)
		return (malloc(n_size));

	if (n_size > old_size)
		tp = old_size;

	if (n_size == 0)
	{
		free(pot);
		return (NULL);
	}

	p = malloc(n_size);

	for (i = 0; i < tp; i++)
		p[i] = ((char *)pot)[i];
	free(pot);
	return (p);
}
