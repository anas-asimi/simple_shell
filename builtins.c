#include "main.h"

/**
 * _intgtostrg - is the function that conver from int to string
 * @number: is the int we want to convert
 * Return: return the string
 */

char *_intgtostrg(int number)
{
	int i = 0, j = 0, k = 0, l = 0, m = 0;
	char *strg = NULL;

	if (number == 0)
	{
		strg = malloc(sizeof(char) * 2);
		if (strg == NULL)
			return (NULL);
		strg[0] = '0';
		strg[1] = '\0';
		return (strg);
	}
	if (number < 0)
		l = 1;
	m = number;
	while (m != 0)
	{
		m /= 10;
		i++;
	}
	strg = malloc(sizeof(char) * (i + 1 + l));
	if (strg == NULL)
		return (NULL);
	if (l == 1)
		strg[0] = '-';
	for (j = i - 1 + l; j >= l; j--)
	{
		k = number % 10;
		if (k < 0)
			k *= -1;
		strg[j] = k + '0';
		number /= 10;
	}
	strg[i + l] = '\0';
	return (strg);
}

/**
 * args_echo - the function that handel $
 * @status:  the exit status
 * @index:  tokens (it's a string)
 */

void args_echo(char *index, int status)
{
	char *value = NULL;

	if (index == NULL)
	{
		write(STDOUT_FILENO, "\n", 1);
		return;
	}
	if (_strgs_cmpr(index, "$", 1) == 0)
	{
		value = _get_env_var(index + 1);
		if (value != NULL)
		{
			write(STDOUT_FILENO, value, _strg_len(value));
			write(STDOUT_FILENO, "\n", 1);
			return;
		}
	}
	if (_strgs_cmpr(index, "$$", 2) == 0)
	{
		value = _intgtostrg(getpid());
		write(STDOUT_FILENO, value, _strg_len(value));
		write(STDOUT_FILENO, "\n", 1);
		free(value);
		return;
	}
	if (_strgs_cmpr(index, "$?", 2) == 0)
	{
		value = _intgtostrg(status);
		write(STDOUT_FILENO, value, _strg_len(value));
		write(STDOUT_FILENO, "\n", 1);
		free(value);
		return;
	}
	write(STDOUT_FILENO, "\n", 1);
}

/**
 * built_in_echo - is the function that built in echo
 * @dt: is the data
 */

void built_in_echo(data *dt)
{
	int i = 1, flag = 0, j = 0;
	int x, y, z;

	if (dt->argv[1] == NULL)
	{
		write(STDOUT_FILENO, "\n", 1);
		return;
	}
	if (_strgs_cmpr(dt->argv[0], "echo", 4) != 0)
		return;
	for (i = 1; dt->argv[i] != NULL; i++)
	{
		x = _strgs_cmpr(dt->argv[1], "$", 1) == 0;
		y = _strgs_cmpr(dt->argv[1], "$$", 2) == 0;
		z = _strgs_cmpr(dt->argv[1], "$?", 2) == 0;
		if (x || y || z)
		{
			args_echo(dt->argv[1], dt->last_exit_status);
			return;
		}
		for (i = 1; dt->argv[i] != NULL; i++)
		{
			for (j = 0; dt->argv[i][j] != '\0'; j++)
			{
				if (dt->argv[i][j] == '$')
				{
					flag = 1;
					args_echo(dt->argv[i] + j, dt->last_exit_status);
					break;
				}
				if (dt->argv[i][j] != '"')
					write(STDOUT_FILENO, &dt->argv[i][j], 1);
			}
			if (dt->argv[i + 1] != NULL)
				write(STDOUT_FILENO, " ", 1);
		}
	}
	if (flag == 0)
		write(STDOUT_FILENO, "\n", 1);
}
