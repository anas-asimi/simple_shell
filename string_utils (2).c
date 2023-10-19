#include "main.h"

/**
 * print_string :  function to print a string
 * @strg: is the string to print
 * Return: void
 */
void print_string(const char *strg)
{
	if (!strg)
		return;
	while (*strg)
	{
		write(STDOUT_FILENO, strg, 1);
		strg++;
	}
}

/**
 * free_arrays - is the function that free arrays
 * @array: is the array to free it
 * Return: void
 */
void free_arrays(char **array)
{
	int i;

	if (!array)
		return;

	for (i = 0; array[i]; i++)
	{
		free(array[i]);
		array[i] = NULL;
	}

	free(array);
}

/**
 * _strgsplit - is the function that split a string by delem
 * @delim: the delimiters
 * @dt: is the data
 * Return: void
 */
void _strgsplit(data *dt, const char *delim)
{
	char *token;
	int ntoken = 0;

	dt->argv = malloc(2 * sizeof(char *));
	if (dt->argv == NULL)
	{
		free(dt->cmd);
		perror(dt->shell_name);
		exit(EXIT_FAILURE);
	}
	dt->argv[0] = NULL;
	dt->argv[1] = NULL;

	token = strtok(dt->cmd, delim);
	while (token)
	{
		dt->argv = realloc(dt->argv, (ntoken + 2) * sizeof(char *));
		if (dt->argv == NULL)
			goto free;
		dt->argv[ntoken] = _strg_dup(token);
		if (dt->argv[ntoken] == NULL)
			goto free;
		ntoken++;
		token = strtok(NULL, delim);
	}
	dt->argv[ntoken] = NULL;
	return;
free:
	free_arrays(dt->argv);
	free(dt->cmd);
	perror(dt->shell_name);
	exit(EXIT_FAILURE);
}

/**
 * init_dt : is the function that intialisate the data
 * @shell_name: is the shell name where we work
 * @dt: is the data
 * Return: void
 */

void init_dt(data *dt, const char *shell_name)
{
	dt->cmd = NULL;
	dt->argv = NULL;
	dt->shell_name = shell_name;
	dt->last_exit_status = EXIT_SUCCESS;
	dt->flag_setenv = 0;
}

/**
 * _read_cmnd :  function that read the commandand storet
 * @dt: is the data
 * Return: void
 */
void _read_cmnd(data *dt)
{
	size_t n = 0;
	ssize_t nread;
	int i = 0;

	nread = _getline(&dt->cmd, &n, stdin);

	if (nread == -1)
	{
		free(dt->cmd);
		exit(EXIT_SUCCESS);
	}

	dt->cmd[nread - 1] = '\0';
	_trim_strg(dt->cmd);
	for (i = 0; dt->cmd[i] != '\0'; i++)
	{
		if (dt->cmd[0] == '#' || (dt->cmd[i] == '#' && dt->cmd[i - 1] == ' '))
		{
			dt->cmd[i] = '\0';
			break;
		}
	}
	_trim_strg(dt->cmd);
}
