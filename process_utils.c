#include "main.h"

/**
 * run_prosses - is the function to run the prosses
 * @dt: is the data
 * Return: void
 */

void run_prosses(data *dt)
{
	pid_t child_pid = fork();
	int status = 0;

	if (child_pid == -1)
		goto free;
	if (child_pid == 0 && execve(dt->argv[0], dt->argv, NULL) == -1)
		goto free;
	else if (wait(&status) == -1)
		goto free;
	if (WIFEXITED(status))
		dt->last_exit_status = WEXITSTATUS(status);
	return;
free:
	perror(dt->shell_name);
	free_arrays(dt->argv);
	free(dt->cmd);
	exit(EXIT_FAILURE);
}

/**
 * handl_sig - is the function that hundel the signal
 * @signal: is the input
 * Return: void
 */

void handl_sig(int signal)
{
	/*const char prompt[] = PROMPT;*/
	(void)signal;
	exit(EXIT_FAILURE);
	/*_printf(prompt);*/
}

/**
 * _exe_cmnd - is the function that exectute command
 * @dt: is the data
 * Return: void
 */

void _exe_cmnd(data *dt)
{
	const char prompt[] = PROMPT;

	signal(SIGINT, handl_sig);

	while (1)
	{
		if (isatty(STDIN_FILENO))
			print_string(prompt);

		_read_cmnd(dt);
		if (_strg_len(dt->cmd) != 0)
		{
			_strgsplit(dt, " ");
			if (!exec_built_in(dt))
			{
				_cmnd_path(dt);
				if (access(dt->argv[0], F_OK) == -1)
				{
					perror(dt->shell_name);
				}
				else
				{
					run_prosses(dt);
				}
			}
			free_arrays(dt->argv);
		}
		free(dt->cmd);
	}
}
