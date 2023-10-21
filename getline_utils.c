#include "main.h"

/**
 * _sizeto_getline - function that give the size to getline
 * @strlip: the string input
 * @strsiz: the size of the string
 * Return: intger
 */
int _sizeto_getline(char **strlip, size_t *strsiz)
{
	if (*strlip == NULL || *strsiz == 0)
	{
		*strsiz = 128;
		*strlip = malloc(*strsiz);
		if (*strlip == NULL)
			return (-1);
	}
	return (0);
}

/**
 * _getline - funtion that reads the input of the user
 * @strlip: the string input
 * @strsiz: the size of the string
 * @stream: FILE input
 * Return: ssize_t
 */
ssize_t _getline(char **strlip, size_t *strsiz, FILE *stream)
{
	ssize_t _nbytes = 0;
	size_t position = 0, size;
	static char buffer[READ_BUF_SIZE];
	static size_t buffersize, bufferpos;
	char *newbuffer;

	if (strlip == NULL || strsiz == NULL || stream == NULL)
		return (-1);
	if (_sizeto_getline(strlip, strsiz) == -1)
		return (-1);
	while (1)
	{
		if (bufferpos >= buffersize)
		{
			_nbytes = read(stream->_fileno, buffer, READ_BUF_SIZE);
			if (_nbytes <= 0 && position == 0)
				return (-1);
			else if (_nbytes <= 0)
				break;
			buffersize = _nbytes;
			bufferpos = 0;
		}
		if (position >= *strsiz - 1)
		{
			size = *strsiz * 2;
			newbuffer = realloc(*strlip, size);
			if (newbuffer == NULL)
				return (-1);
			*strlip = newbuffer;
			*strsiz = size;
		}
		(*strlip)[position++] = buffer[bufferpos++];
		if ((*strlip)[position - 1] == '\n')
			break;
	}
	(*strlip)[position] = '\0';
	return (position);
}
