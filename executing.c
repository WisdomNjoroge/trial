#include "shell.h"

/**
 * executing_command - execute a shell command
 *
 * @command: a string representing the command to be excuted
 */
void executing_command(const char *command)
{
	pid_t pid;
	int status, m = 0;
	char *args[MAX_COMMAND_LENGTH], *tkn;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		tkn = strtok((char *)command, " ");
		while (tkn != NULL && m < MAX_COMMAND_LENGTH - 1)
		{
			args[m] = tkn;
			tkn = strtok(NULL, " ");
			m++;
		}
		args[m] = NULL;

		execvp(args[0], args); /* Child process code (executing command) */
		perror("execvp");
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
