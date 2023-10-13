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
 * *_strsplit - function that split a string.
 * @str: string.
 * @delim: delim.
 * Return: pointer to array of char pointers.
 */
char **_strsplit(char *str, const char *delim)
{
	int i, total_of_strings;
	char **array;
	char *token;
	char *str_copy1;
	char *str_copy2;

	str_copy1 = _strcpy(str);
	str_copy2 = _strcpy(str_copy1);

	token = strtok(str_copy1, delim);
	while (token != NULL)
	{
		total_of_strings++;
		token = strtok(NULL, delim);
	}
	total_of_strings++;

	array = malloc(sizeof(char *) * total_of_strings);
	if (array == NULL)
		return (NULL);

	token = strtok(str_copy2, delim);
	for (i = 0; token != NULL; i++)
	{
		array[i] = malloc(sizeof(char) * _strlen(token));
		array[i] = _strcpy(token);
		token = strtok(NULL, delim);
	}
	array[i] = NULL;
	free(str_copy1);
	free(str_copy2);
	return (array);
}

/**
 * *_strconcat - function that concatenate list of strings.
 * @array_of_strings: array of strings.
 * @delim: delim.
 * Return: pointer to string.
 */
char *_strconcat(char **array_of_strings, const char *delim)
{
	int full_length, i, j, x;
	char *str;

	full_length = 0;
	for (i = 0; array_of_strings[i]; i++)
	{
		for (j = 0; array_of_strings[i][j]; j++)
		{
			full_length++;
		}
	}
	full_length += ((i - 1) * _strlen((char *)delim));

	str = malloc(sizeof(char) * (full_length + 1));
	if (str == NULL)
		return (NULL);

	x = 0;
	for (i = 0; array_of_strings[i]; i++)
	{
		for (j = 0; array_of_strings[i][j]; j++)
		{
			str[x++] = array_of_strings[i][j];
		}
		for (j = 0; delim[j]; j++)
		{
			str[x++] = delim[j];
		}
	}
	str[full_length] = '\0';
	return (str);
}
