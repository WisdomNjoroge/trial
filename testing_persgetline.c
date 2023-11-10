#include "shell.h"

int main(void)
{
	char *line;

	printf("Enter a line of text (or press Ctrl+D to exit):\n");

	while ((line = pers0nal_getline()) != NULL)
	{
		printf("You entered: %s\n", line);
		free(line);
		printf("Enter anothe line of text (or press Ctrl+D to exit:\n");
	}

	printf("\n");

	return (0);
}
