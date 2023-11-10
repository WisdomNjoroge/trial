#include "shell.h"

/**
 * main - entry point of the shell program
 * This function serves as the main entry point for basic shell program
 * Reads user input , creates child processes to execute commands and
 * waits for them to complete
 * @command: a string representing the command to be executed
 * Return: 0 on success, non-zero on failure
 */
void executing_command(const char *command);

int main(void)
{
	char **env = environ;
	char command[MAX_COMMAND_LENGTH];
	char *line;

	display_prompt(); /* Display the shell prompt to the user */
	while (fgets(command, MAX_COMMAND_LENGTH, stdin) != NULL)
	{
		command[strcspn(command, "\n")] = '\0';

		if (strcmp(command, "exit") == 0)
		{
			printf("Exiting the shell$.\n");
			exit(EXIT_SUCCESS);
		}
		else if (strcmp(command, "env") == 0)
		{
			while (*env != NULL)
			{
				printf("%s\n", *env);
				env++;
			}
		}
		executing_command(command);
		line = pers0nal_getline();
		if (line == NULL)
		{
			break;
		}
		printf("You entered: %s\n", line);
		free(line);
	}

	printf("\n");
	return (0); /* Exit the shell with a status of 0 (success) */
}
