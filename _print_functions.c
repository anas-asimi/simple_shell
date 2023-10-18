#include "main.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_string - writes the string c to stdout
 * @s: The string to print
 *
 * Return: On success number of printed characters.
 * On error: NULL
 */
int print_string(char *s)
{
	int i;

	i = 0;
	if (s == NULL)
		return (-1);
	while (s[i])
		_putchar(s[i++]);
	return (i);
}
