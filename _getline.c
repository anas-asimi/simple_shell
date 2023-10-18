#include "main.h"

#define BUFFER_SIZE 1024


/**
 * _getline - get input.
 * Return: string.
 */
char *_getline(void)
{
	char buffer[BUFFER_SIZE];
	ssize_t bytesRead;
	char *result;
	size_t resultSize;
	char *newResult;

	result = NULL;
	resultSize = 0;
	while ((bytesRead = read(STDIN_FILENO, buffer, BUFFER_SIZE)) > 0)
	{
		newResult = (char *)realloc(result, resultSize + bytesRead + 1);
		if (newResult == NULL)
		{
			perror("realloc");
			free(result);
			return (NULL);
		}
		result = newResult;

		memcpy(result + resultSize, buffer, bytesRead);
		resultSize += bytesRead;
	}

	if (bytesRead < 0)
	{
		perror("read");
		free(result);
		return (NULL);
	}

	if (result != NULL)
	{
		result[resultSize] = '\0';
	}

	return (result);
}
