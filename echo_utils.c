#include "main.h"

/**
 * exec_built_in - function that run the built in functions
 * @dt: is the data
 * Return: 1 if built in, 0 if not
 */
int exec_built_in(data *dt)
{
	builtin builtin[] = {
		{"exit", exit_built_in},
		{"env", env_built_in},
		{"setenv", setenv_built_in},
		{"unsetenv", unsetenv_built_in},
		{"cd", cd_built_in},
		{NULL, NULL},
	};
	int i = 0;

	for (i = 0; builtin[i].cmd; i++)
	{
		if (_strg_cmpr(dt->argv[0], builtin[i].cmd) == 0)
		{
			builtin[i].f(dt);
			return (1);
		}
	}
	return (0);
}

/**
 * exit_built_in - fucntion to exit the shell
 * @dt: is the data
 * Return: void
 */
void exit_built_in(data *dt)
{
	const char *errstr = "./hsh: 1: exit: Illegal number: ";

	if (dt->argv[1])
	{
		if (dt->argv[1][0] != '-' && _if_strg_num(dt->argv[1]))
			dt->last_exit_status = atoi(dt->argv[1]);
		else
		{
			write(STDERR_FILENO, errstr, strlen(errstr));
			write(STDERR_FILENO, dt->argv[1], strlen(dt->argv[1]));
			write(STDERR_FILENO, "\n", 1);
			dt->last_exit_status = 2;
		}
	}
	free_arrays(dt->argv);
	free(dt->cmd);
	if (dt->flag_setenv)
		free_arrays(environ);
	exit(dt->last_exit_status);
}

/**
 * env_built_in - function that prints the environment
 * @d: is the data
 * Return: void
 */
void env_built_in(data *d)
{
	int i = 0;

	(void)d;
	while (environ[i])
	{
		print_string(environ[i]);
		print_string("\n");
		i++;
	}
}
/**
 * setenv_built_in - function that add a environment variable
 * @d: is the data
 * Return: void
 */

void setenv_built_in(data *d)
{
	(void)d;
	if (d->argv[1] && d->argv[2])
	{
		if (_set_env(d, d->argv[1], d->argv[2]) == -1)
		{
			perror("setenv");
		}
	}
}

/**
 * unsetenv_built_in -  functioin that remove an environment variable
 * @d: is the data
 * Return: void
 */
void unsetenv_built_in(data *d)
{
	int i, j;
	int len;

	(void)d;
	if (!d->argv[1] || !getenv(d->argv[1]))
	{
		_prt_error(d->shell_name, "variable not found.");
		return;
	}
	len = strlen(d->argv[1]);
	for (i = 0; environ[i]; i++)
		if (strncmp(environ[i], d->argv[1], len) == 0 && environ[i][len] == '=')
			for (j = i; environ[j]; j++)
				environ[j] = environ[j + 1];
}
