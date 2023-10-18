#include "main.h"

/**
 * read_line - read input.
 * Return: string.
 */
char *read_line(void)
{
	char *line;
	size_t bufsize;

	line = NULL;
	bufsize = 0;
	if (getline(&line, &bufsize, stdin) == -1)
	{
		free(line);
		return (NULL);
	}
	return (line);
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

/**
 * read_stream - read a line from the stream
 *
 * Return: pointer that points the the read line
 */
char *read_stream(void)
{
	int bufsize = 1024;
	int i = 0;
	char *line = malloc(sizeof(char) * bufsize);
	int character;

	if (line == NULL)
	{
		fprintf(stderr, "allocation error in read_stream");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		character = getchar(); /* read first char from stream */
		if (character == EOF)
		{
			free(line);
			exit(EXIT_SUCCESS);
		}
		else if (character == '\n')
		{
			line[i] = '\0';
			return (line);
		}
		else
		{
			line[i] = character;
		}
		i++;
		if (i >= bufsize)
		{
			bufsize += bufsize;
			line = realloc(line, bufsize);
			if (line == NULL)
			{
				fprintf(stderr, "reallocation error in read_stream");
				exit(EXIT_FAILURE);
			}
		}
	}
}
