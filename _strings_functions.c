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
 * @s: string.
 * Return: pointer to array of char pointers.
 */
char **_strsplit(char *str, const char *delim)
{
	int i, total_of_strings;
	char **array;
	char *token;
	char *srt_copy1;
	char *srt_copy2;

	srt_copy1 = _strcpy(str);
	srt_copy2 = _strcpy(str);

	token = strtok(srt_copy1, delim);
	while (token != NULL)
	{
		total_of_strings++;
		token = strtok(NULL, delim);
	}
	total_of_strings++;

	array = malloc(sizeof(char *) * total_of_strings);
	if (array == NULL)
		return (NULL);

	token = strtok(srt_copy2, delim);
	for (i = 0; token != NULL; i++)
	{
		array[i] = malloc(sizeof(char) * _strlen(token));
		array[i] = _strcpy(token);
		token = strtok(NULL, delim);
	}
	array[i] = NULL;
	free(srt_copy1);
	free(srt_copy2);
	return (array);
}
