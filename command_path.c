#include "main.h"

/**
 * _get_env_var - is the function that get the environment variable.
 * @key: is the key of the variable
 * Return: value of an environment variable
 */

char *_get_env_var(char *key)
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
		if (!_strgs_cmpr(environ[i], key, key_len) && environ[i][key_len] == '=')
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
	char *token, *path,
		*paths = malloc(_strg_len(_get_env_var("PATH") ? _get_env_var("PATH") : "") + 1);
	size_t token_len;
	int find = -1;

	if (!_get_env_var("PATH"))
		goto step_out;
	_str_copy(paths, _get_env_var("PATH"));
	if (paths == NULL)
		goto step_out;
	token = strtok(paths, ":");
	while (token)
	{
		token_len = _strg_len(token) + _strg_len(dt->av[0]) + 2;
		path = malloc(token_len);
		if (path == NULL)
			return (find);
		_str_copy(path, token);
		_strg_cat(path, "/");
		_strg_cat(path, dt->av[0]);
		if (access(path, F_OK) == 0)
		{
			free(dt->av[0]);
			dt->av[0] = _strg_dup(path);
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

	_str_copy(crt_new, key);
	strcat(crt_new, "=");
	strcat(crt_new, valeur);

	return (crt_new);
}

/**
 * new_env : is the functio for the new environ
 * @key: is the key
 * @valeur: is the value of the variabl
 * Return: void
 */
char **new_env(char *key, char *valeur)
{
	int env_len = 0, i = 0;
	char *entry_n;
	char **new_environ;

	while (environ[env_len])
		env_len++;
	entry_n = crt_new(key, valeur);
	if (entry_n == NULL)
		return (NULL);
	new_environ = _get_env_var(key) ? malloc((env_len + 1) * sizeof(char *))
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
		if (strncmp(environ[i], key, strlen(key)) == 0
		&& environ[i][strlen(key)] == '=')
			_str_copy(new_environ[i], entry_n);
		else
			_str_copy(new_environ[i], environ[i]);
	}
	if (!_get_env_var(key))
	{
		new_environ[env_len] = entry_n;
		new_environ[env_len + 1] = NULL;
	}
	else
		new_environ[env_len] = NULL;
	return (new_environ);
}

/**
 * _set_env : is the function to set a new value to key
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
