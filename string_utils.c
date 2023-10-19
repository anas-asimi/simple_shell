#include "main.h"

/**
 * _strg_len - this function return length of a string
 * @strg: the string
 * Return: len of string.
 */

unsigned int _strg_len(char *strg)
{
	unsigned int i;

	for (i = 0; strg[i] != '\0'; i++)
		;
	return (i);
}


/**
 * _strg_cmpr - this function compares two strings.
 * @strg1: string 1
 * @strg2: string 2
 * Return: the result
 */

int _strg_cmpr(const char *strg1, const char *strg2)
{
	int i;
	int res = 0;

	for (i = 0; strg1[i] != '\0' && strg2[i] != '\0'; i++)
	{
		if (strg1[i] != strg2[i])
		{
			res = strg1[i] - strg2[i];
			break;
		}
	}

	return (res);
}

/**
 * _strgs_cmpr - this function compares two strings with a number
 * @strg1: string 1
 * @strg2: string 2
 * @n: how many char you want compare
 * Return: the result
 */
int _strgs_cmpr(const char *strg1, const char *strg2, int n)
{
	int i;
	int res = 0;

	for (i = 0; strg1[i] != '\0' && strg2[i] != '\0'; i++)
	{

		if (i >= n)
			break;
		if (strg1[i] != strg2[i])
		{
			res = strg1[i] - strg2[i];
			break;
		}
	}

	return (res);
}

/**
 * _strg_copy : copy strg (src) to dest .
 * @dest: input char *
 * @src: input const char *
 * Return: char *
 */
char *_strg_copy(char *dest, const char *src)
{
	int len;

	for (len = 0; src[len] != '\0'; ++len)
	{
		dest[len] = src[len];
	}
	dest[len] = '\0';
	return (dest);
}

/**
 * _strg_cat - appends the src string to the dest string,
 * @dest: input string
 * @src: input const string
 * Return: void
 */
char *_strg_cat(char *dest, const char *src)
{
	char *result = dest;

	while (*dest != '\0')
		dest++;

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';

	return (result);
}
