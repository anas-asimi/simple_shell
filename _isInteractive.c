#include "main.h"


/**
 * isInteractive - get input.
 * Return: number.
 */
int isInteractive(void)
{
	/* function bax n3rfo shell dyalna is Interactive or no*/
	return (isatty(STDIN_FILENO));
}
