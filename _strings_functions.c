#include "main.h"

/**
 * _strlen - returns length os string.
 * @s: string to evaluate
 * Return: int.
 */
int _strlen(char *s)
{
	int length = 0;

	while (s[length])
		length++;
	return (length);
}

/**
 * _strlen_deli - returns length os string.
 * @s: string to evaluate
 * @deli: delimetre
 * Return: int.
 */
int _strlen_deli(char *s, char deli)
{
	int length = 0;

	while (s[length])
		length++;
	return (length);
}

/**
 * *_strcpy - function that return copies of the string.
 * @src: source.
 * Return: copy of the string.
 */

char *_strcpy(char *src)
{
	int len, i = 0;
	char *copy;

	len = _strlen(src);
	copy = malloc(sizeof(char) * (len + 1));
	if (copy == NULL)
		return (NULL);

	for (i = 0; i < len; i++)
		copy[i] = src[i];
	copy[len] = '\0';
	return (copy);
}

/**
 * *_strcpy_from_to - function that return copies of the string.
 * @src: source.
 * Return: copy of the string.
 */

char *_strcpy_from_to(char *src, int start, int end)
{
	int len, i = 0;
	char *copy;

	len = end - start;
	copy = malloc(sizeof(char) * (len + 1));
	if (copy == NULL)
		return (NULL);

	for (i = 0; i < len; i++)
		copy[i] = src[i + start];
	copy[len] = '\0';
	return (copy);
}

/**
 * *_strsplit - function that split a string.
 * @s: string.
 * Return: pointer to array of char pointers.
 */

char **_strsplit(char *str, char deli)
{
	int total_of_strings, i, current_index, current_string_index, current_string_len;
	char **array;

	if (str == NULL)
		return (NULL);

	total_of_strings = 1;
	i = 0;
	while (str[i])
	{
		if (str[i++] == deli)
			total_of_strings++;
	}
	array = malloc(sizeof(char *) * total_of_strings + sizeof(NULL));
	if (array == NULL)
		return (NULL);

	current_index = 0;
	current_string_index = 0;
	while (1)
	{
		if (current_string_index > total_of_strings)
			break;
		current_string_len = _strlen_deli(str + current_index, deli);
		array[current_string_index] = _strcpy_from_to(str, current_index, current_index + current_string_len);
		current_index += current_string_len + 1;
		current_string_index++;
	}
	return (array);
}
