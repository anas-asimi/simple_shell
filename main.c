#include "main.h"

/**
 * main - entry point
 * @ac: arg count
 * @av: arg vector
 *
 * Return: 0 on success, 1 on error
 */
int main(int ac, char **av)
{
	int status;
	char *command;
	char **command_as_token;

	(void)ac;
	if (isatty(STDIN_FILENO)) /* shell is running in interactive mode*/
	{
		while (1)
		{
			print_prompt();
			command = read_line();
			if (command == NULL)
			{
				_putchar('\n');
				break;
			}
			command_as_token = _strsplit(command, " \n");
			status = _execute(command_as_token);
			free(command);
			free_array(command_as_token);
			if (status == 1)
				perror(av[0]);
		}
	}
	else /* shell is running in non interactive mode*/
	{
		command = read_stream();
		command_as_token = _strsplit(command, " \n");
		status = _execute(command_as_token);
		free(command);
		free_array(command_as_token);
		if (status == 1)
			perror(av[0]);
	}
	return (status);
}
