#include "main.h"

/**
 * chang_dire - is the function that change the directory, pwd and oldpwd
 * @targ_dir: is dir where the user want cd to it
 */

void chang_dire(char *targ_dir)
{
	char *pwd = getcwd(NULL, 0);
	char error_msg[100];
	const char *prefix = "./hsh: 1: cd: can't cd to ";
	int i, j;
	const char *suffix = "\n";

	if (pwd == NULL)
	{
		perror("getcwd");
		return;
	}
	if (chdir(targ_dir) == -1)
	{
		for (i = 0; prefix[i] != '\0'; i++)
			error_msg[i] = prefix[i];
		for (j = 0; targ_dir[j] != '\0'; j++, i++)
			error_msg[i] = targ_dir[j];
		for (j = 0; suffix[j] != '\0'; j++, i++)
			error_msg[i] = suffix[j];
		error_msg[i] = '\0';
		write(STDERR_FILENO, error_msg, i);
		free(pwd);
		return;
	}
	if (setenv("PWD", targ_dir, 1) != 0)
	{
		perror("setenv");
		free(pwd);
		return;
	}
	if (setenv("OLDPWD", pwd, 1) != 0)
		perror("setenv");
	free(pwd);
}

/**
 * cd_built_in - is the function that get the dir that the user want it
 * @dt: is the data
 */

void cd_built_in(data *dt)
{
	char *targ_dir = NULL, *oldpwd = NULL;

	if (dt->argv[1] == NULL)
	{
		targ_dir = _get_EV("HOME");
	}
	else if (strcmp(dt->argv[1], "-") == 0)
	{
		targ_dir = _get_EV("OLDPWD");
		if (targ_dir == NULL)
		{
			write(STDERR_FILENO, "OLDPWD not set\n", 14);
			return;
		}
	}
	else
	{
		targ_dir = dt->argv[1];
	}

	oldpwd = getcwd(NULL, 0);
	if (oldpwd == NULL)
	{
		perror("getcwd");
		return;
	}
	chang_dire(targ_dir);
	if (dt->argv[1] != NULL && strcmp(dt->argv[1], "-") == 0)
	{
		write(STDOUT_FILENO, targ_dir, strlen(targ_dir));
		write(STDOUT_FILENO, "\n", 1);
	}
	free(oldpwd);
}
