#include "main.h"

/**
 * _getchar - get char from stdin.
 * Return: character.
 */
char _getchar(void)
{
	char buffer[1];
	int bytesRead;

	bytesRead = read(0, buffer, 1);
	if (bytesRead != 1)
		return (EOF);
	return (buffer[0]);
}

/**
 * _getline - get a line from stdin
 *
 * Return: pointer that points the the read line
 */
char *_getline(void)
{
	int character, bufferSize, i;
	char *line;

	bufferSize = 1024;
	i = 0;
	line = malloc(sizeof(char) * bufferSize);

	if (line == NULL)
	{
		perror("allocation error in read_stream");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		character = _getchar();
		if (character == EOF)
		{
			free(line);
			return (NULL);
		}
		else if (character == '\n')
		{
			line[i] = '\0';
			return (line);
		}
		else
			line[i] = character;
		i++;
		if (i >= bufferSize)
		{
			bufferSize += bufferSize;
			line = _realloc(line, bufferSize);
			if (line == NULL)
			{
				perror("reallocation error in read_stream");
				exit(EXIT_FAILURE);
			}
		}
	}
}

/**
 * free_array - read input.
 * @array: array
 * Return: string.
 */
void free_array(char **array)
{
	int i;

	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
}

/**
 * _get_location - get location of command.
 * @command: command
 * Return: int.
 */
char *_get_location(char *command)
{
	char *path, *path_copy, *path_token, *file_path;
	char *array_of_strings[3];
	struct stat buffer;

	path = getenv("PATH");
	if (path == NULL)
		return (NULL);

	path_copy = _strcpy(path);
	path_token = strtok(path_copy, ":");
	while (path_token != NULL)
	{
		array_of_strings[0] = path_token;
		array_of_strings[1] = command;
		array_of_strings[2] = NULL;
		file_path = _strconcat(array_of_strings, "/");
		if (stat(file_path, &buffer) == 0)
		{
			return (file_path);
		}
		else
		{
			free(file_path);
			path_token = strtok(NULL, ":");
		}
	}
	if (stat(command, &buffer) == 0)
	{
		return (command);
	}
	return (NULL);
}

/**
 * _execute - run command.
 * @token: command as token
 * Return: int.
 */
int _execute(char **token)
{
	pid_t pid;
	int status;
	char *location;

	location = _get_location(token[0]);
	if (location == NULL)
		return (1);

	fflush(stdout);
	pid = fork();
	if (pid == 0)
	{
		execve(location, token, environ);
	}
	else
		waitpid(pid, &status, 0);
	return (status);
}
