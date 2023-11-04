#include "shell.h"

void executing_command(const char *command)
{
	pid_t pid;
	int status;

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
