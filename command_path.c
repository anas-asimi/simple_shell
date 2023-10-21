#include "main.h"

/**
 * _get_EV - is the function that get the environment variable.
 * @key: is the key of the variable
 * Return: value of an environment variable
 */

char *_get_EV(char *key)
{
	int i = -1;
	size_t key_len;

	if (key == NULL || *key == '\0')
		return (NULL);
	if (environ == NULL)
		return (NULL);

	key_len = _strg_len(key);

	while (environ[++i])
	{
		if (!_strcmp(environ[i], key, key_len) && environ[i][key_len] == '=')
		{
			return (environ[i] + key_len + 1);
		}
	}
	return (NULL);
}

/**
 * _cmnd_path - is the function that alocate the path of the command
 * @dt: is the data
 * Return: void
 */
int _cmnd_path(data *dt)
{
	char *token, *path, *paths;
	size_t token_len;
	int find = -1;

	paths = malloc(_strg_len(_get_EV("PATH") ? _get_EV("PATH") : "") + 1);
	if (!_get_EV("PATH"))
		goto step_out;
	_strg_copy(paths, _get_EV("PATH"));
	if (paths == NULL)
		goto step_out;
	token = strtok(paths, ":");
	while (token)
	{
		token_len = _strg_len(token) + _strg_len(dt->argv[0]) + 2;
		path = malloc(token_len);
		if (path == NULL)
			return (find);
		_strg_copy(path, token);
		_strg_cat(path, "/");
		_strg_cat(path, dt->argv[0]);
		if (access(path, F_OK) == 0)
		{
			free(dt->argv[0]);
			dt->argv[0] = _str_dup(path);
			free(path);
			find = 0;
			break;
		}
		free(path);
		token = strtok(NULL, ":");
	}
step_out:
	free(paths);
	return (find);
}

/**
 * crt_new - is the function that create a new entry
 * @key: is the key
 * @valeur: is the value of the variabl
 * Return: void
 */
char *crt_new(char *key, char *valeur)
{
	size_t new_len = strlen(key) + strlen(valeur) + 2;
	char *crt_new = malloc(new_len);

	if (crt_new == NULL)
		return (NULL);

	_strg_copy(crt_new, key);
	strcat(crt_new, "=");
	strcat(crt_new, valeur);

	return (crt_new);
}

/**
 * new_env - is the functio for the new environ
 * @key: is the key
 * @valeur: is the value of the variabl
 * Return: void
 */
char **new_env(char *key, char *valeur)
{
	int env_len = 0, i = 0, x, y;
	char *entry_n, **new_environ;

	while (environ[env_len])
		env_len++;
	entry_n = crt_new(key, valeur);
	if (entry_n == NULL)
		return (NULL);
	new_environ = _get_EV(key) ? malloc((env_len + 1) * sizeof(char *))
							   : malloc((env_len + 2) * sizeof(char *));
	if (!new_environ)
	{
		free(entry_n);
		return (NULL);
	}
	for (i = 0; environ[i]; i++)
	{
		new_environ[i] = malloc(strlen(environ[i]) + 1);
		if (!new_environ[i])
		{
			free_arrays(new_environ);
			free(entry_n);
			return (NULL);
		}
		x = strncmp(environ[i], key, strlen(key)) == 0;
		y = environ[i][strlen(key)] == '=';
		if (x && y)
			_strg_copy(new_environ[i], entry_n);
		else
			_strg_copy(new_environ[i], environ[i]);
	}
	if (!_get_EV(key))
	{
		new_environ[env_len] = entry_n;
		new_environ[env_len + 1] = NULL;
	}
	else
		new_environ[env_len] = NULL;
	return (new_environ);
}

/**
 * _set_env - is the function to set a new value to key
 * @dt: is the data
 * @key: is the key
 * @valeur: is the value of the variable
 * Return: void
 */
int _set_env(data *dt, char *key, char *valeur)
{
	char **new_environ;

	if (!key || !valeur)
		return (-1);

	new_environ = new_env(key, valeur);
	if (!new_environ)
		return (-1);
	environ = new_environ;
	dt->flag_setenv = 1;

	return (0);
}
