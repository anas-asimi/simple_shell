#include "main.h"
_isdigit
/**
 * _strg_dup - returns a pointer to a newly allocated space in memory,
 * which contains a copy of the string given as a parameter.
 * @strg: string input
 * Return: pointer
 */

char *_str_dup(const char *strg)
{
	int i, len = 0;
	char *result;

	if (strg == NULL)
		return (NULL);

	while (strg[len] != '\0')
		len++;

	result = (char *)malloc((len + 1) * sizeof(char));

	if (result == NULL)
		return (NULL);

	for (i = 0; i <= len; i++)
		result[i] = strg[i];

	return (result);
}

/**
 * _if_char_num : check if charachter is number
 * @c: charachter
 * Return: 1 if its a digit 0 otherwise
 */

int _if_char_num(int c)
{
	return (c >= '0' && c <= '9');
}


/**
 * _if_strg_num : check if a string is a number
 * @status: string to be checked
 * Return: void
 */

int _if_strg_num(const char *status)
{
	if (status == NULL || status[0] == '\0')
		return (0);
	while (*status)
	{
		if (!_if_char_num(*status))
			return (0);
		status++;
	}
	return (1);
}
