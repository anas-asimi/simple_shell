#ifndef HEADER_FILE
#define HEADER_FILE

/*
#include <stdarg.h>
#include <limits.h>
#include <stdint.h>
*/
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

/* printing */
int _putchar(char c);
int print_string(char *s);
int print_number(long int n);
int print_unsigned_int(unsigned long int n);

/* strings */
int _strlen(char *s);
int _strlen_deli(char *s, char deli);
char *_strcpy(char *src);
char *_strcpy_from_to(char *src, int start, int end);

/* shell*/
int interactive_shell(void);

#endif
