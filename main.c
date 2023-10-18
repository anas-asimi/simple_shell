#include "main.h"

/**
 * main - entry point to the shell
 * @ac: arg count
 * @av: arg pointer
 *
 * Return: 0 on success, 1 on error
 */
int main(int ac, char **av)
{
	int status;
	char *command;
	char **command_as_token;

	(void)ac;
	if (isInteractive()) /* shell is running in interactive mode */
	{
		while (1)
		{
			print_string("#cisfun$ ");
			command = _getline();
			if (command == NULL)
			{
				_putchar('\n');
				break;
			}
			command_as_token = _strsplit(command, " \n");
			status = _execute(command_as_token);
			free(command);
			free_array(command_as_token);
			if (status != EXIT_SUCCESS)
				perror(av[0]);
		}
	}
	else /* shell is running in non interactive mode */
	{
		command = _getline();
		if (command == NULL)
		{
			perror(av[0]);
			return (EXIT_FAILURE);
		}
		command_as_token = _strsplit(command, " \n");
		status = _execute(command_as_token);
		free(command);
		free_array(command_as_token);
		if (status != EXIT_SUCCESS)
			perror(av[0]);
	}
	return (status);
}
