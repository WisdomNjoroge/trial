#include "shell.h"

/*
 * main - entry point to the shell program
 * Return: always 0 (success)
 */

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
