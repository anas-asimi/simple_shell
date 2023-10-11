#include "main.h"

/**
 * _strlen - returns length os string.
 * @s: string to evaluate
 * Return: int.
 */
char *get_location(char *command)
{
	char *path, *path_copy, *path_token, *file_path;
	int command_length, directory_length;
	char *array_of_strings[3];
	struct stat buffer;

	path = getenv("PATH");
	if (path)
	{
		path_copy = _strcpy(path);
		command_length = _strlen(command);
		path_token = strtok(path_copy, ":");
		while (path_token != NULL)
		{
			directory_length = _strlen(path_token);
			file_path = malloc(command_length + directory_length + 2);
			if (file_path == NULL)
				return (NULL);
			array_of_strings[0] = path_token;
			array_of_strings[1] = command;
			array_of_strings[2] = NULL;
			file_path = _strconcat(array_of_strings, "/");
			if (stat(file_path, &buffer) == 0)
			{
				free(path_copy);
				return (file_path);
			}
			else
			{
				free(file_path);
				path_token = strtok(NULL, ":");
			}
		}
		free(path_copy);
		if (stat(command, &buffer) == 0)
		{
			return (command);
		}
		return (NULL);
	}
	return (NULL);
}
