#ifndef HEADER_FILE
#define HEADER_FILE

/*
 * #include <stdarg.h>
 * #include <limits.h>
 * #include <stdint.h>
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <sys/wait.h>

/* printing */
int _putchar(char c);
int print_string(char *s);
int print_number(long int n);
int print_unsigned_int(unsigned long int n);
void print_error(char *shell_name, char *command);

/* strings */
int _strlen(char *s);
char *_strcpy(char *src);
char **_strsplit(char *string, const char *delimiter);
char *_strconcat(char **array_of_strings, const char *delim);

/* shell*/
char *_get_location(char *command);
char *read_line(void);
char *read_stream(void);
char *_getline(void);
int _execute(char **token);
void free_array(char **array);

/* global variables */
extern char **environ;

#endif
