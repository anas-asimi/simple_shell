#include "../main.h"

int main(void)
{
	char *line;
	while (1)
	{
		line = readFromStdin();
		printf("line after is : %s\n", line);
	}
	return (0);
}
