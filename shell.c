#include "shell.h"

/**
 * main - entry point of the shell program
 * This function serves as the main entry point for basic shell program
 * Reads user input , creates child processes to execute commands and
 * waits for them to complete
 * Return: 0 on success, non-zero on failure
 */
void executing_command(const char *command);

int main(void)
{
	
	char command[MAX_COMMAND_LENGTH];

	display_prompt(); /* Display the shell prompt to the user */
	while (fgets(command, MAX_COMMAND_LENGTH, stdin) != NULL)
	{
		command[strcspn(command, "\n")] = '\0';

		if (strlen(command) == 0)
		{
			display_prompt();
			continue;
		}
		executing_command(command);
	}
	printf("\n");
	return (0); /* Exit the shell with a status of 0 (success) */
}
