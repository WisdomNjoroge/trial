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
	int  status; /* Stores the exit status of child process */
	char command[MAX_COMMAND_LENGTH];
	pid_t pid; /* Stores the process ID of child process */

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
void executing_command(const char *command)
{
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		execlp(command, command, NULL); /* Child process code (executing command) */
		perror("execlp");
		exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(pid, &status, 0); /* Parent process code (waiting for child) */
		if (WIFEXITED(status) && WEXITSTATUS(status) == 0)
		{
			display_prompt(); /* Command execution succeeded */
		}
		else
		{
			fprintf(stderr, "Error: Command execution failed.\n");
			display_prompt();
		}
	}
}

	printf("\n");
	return (0); /* Exit the shell with a status of 0 (success) */
}
