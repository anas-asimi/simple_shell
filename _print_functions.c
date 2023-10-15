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

/**
 * print_number - function.
 * @n: n.
 * Return: 1.
 */
int print_number(long int n)
{
	unsigned long int x;
	int printed_characters;

	printed_characters = 0;
	if (n < 0)
	{
		_putchar('-');
		printed_characters++;
		x = -n;
	}
	else
		x = n;
	if (x >= 10)
		printed_characters += print_number(x / 10);
	_putchar(x % 10 + '0');
	printed_characters++;
	return (printed_characters);
}

/**
 * print_unsigned_int - function.
 * @n: n.
 * Return: 1.
 */
int print_unsigned_int(unsigned long int n)
{
	unsigned long int x;
	int printed_characters;

	printed_characters = 0;
	x = n;
	if (x >= 10)
	{
		printed_characters += print_unsigned_int(x / 10);
	}
	_putchar(x % 10 + '0');
	printed_characters++;
	return (printed_characters);
}

/**
 * print_error - function.
 * @shell_name: shell_name.
 * @command: command.
 */
void print_error(char *shell_name, char *command)
{
	print_string(shell_name);
	print_string(": 1: ");
	print_string(command);
	print_string(": not found\n");
}

/**
 * print_prompt - function.
 */
void print_prompt()
{
	print_string("$ ");
}
