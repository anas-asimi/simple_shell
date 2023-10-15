#include "../main.h"

int main(void)
{
	char *line;
	char **tokens;

	while (1)
	{
		line = read_line();
		tokens = _strsplit(line, " ");
		printf("line after is : %s\n", line);
	}
	free(line);
	return (0);
}
