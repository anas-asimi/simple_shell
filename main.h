#ifndef HEADER_FILE
#define HEADER_FILE

#define PROMPT "$ "

#include <unistd.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <signal.h>
#include <errno.h>

extern char **environ;

/**
 * struct data - is the struct contian data.
 * @argv: is the argv
 * @cmd: is the command
 * @shell_name: is the name of the shell
 * @last_exit_status: is the last exit status
 * @flag_setenv: we use it to free memory
 */
typedef struct data
{
	char **argv;
	char *cmd;
	const char *shell_name;
	int last_exit_status;
	int flag_setenv;
} data;

/**
 * struct builtin - this is the builtin cd and echo ...
 * @cmd: is the command
 * @f: is the functions of builtin cmd
 */
typedef struct builtin
{
	const char *cmd;
	void (*f)(data *dt);
} builtin;

void print_string(const char *strg);
void free_arrays(char **array);
void _strgsplit(data *dt, const char *delim);
void init_dt(data *dt, const char *shell_name);
void _read_cmnd(data *dt);

int exec_built_in(data *dt);
void exit_built_in(data *dt);
void env_built_in(data *dt);
void setenv_built_in(data *dt);
void unsetenv_built_in(data *dt);
void cd_built_in(data *dt);
void built_in_echo(data *dt);

void run_prosses(data *dt);
void handl_sig(int sig);
void _exe_cmnd(data *dt);

void _prt_error(const char *sr1, const char *sr2);
void _trim_strg(char *strg);
void *_fuc_realloc(void *pot, unsigned int n_size);

char *_str_dup(const char *strg);
int _if_strg_num(const char *status);
int _if_char_num(int c);

char *_get_env_var(char *key);
int _cmnd_path(data *dt);
int _set_env(data *dt, char *key, char *valeur);

unsigned int _strg_len(char *strg);
int _strg_cmpr(const char *strg1, const char *strg2);
int _strgs_cmpr(const char *strg1, const char *strg2, int n);
char *_strg_copy(char *dest, const char *src);
char *_strg_cat(char *dest, const char *src);


#define READ_BUF_SIZE 1024

ssize_t _getline(char **lineptr, size_t *n, FILE *stream);


#endif
