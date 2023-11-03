#include "shell.h"

void display_prompt()
{
	printf("#cisfun$ ");
	fflush(stdout);
}

int main(void)
{
	int  status;
	char command[MAX_COMMAND_LENGTH];
	pid_t pid;
	display_prompt();

	while (fgets(command, MAX_COMMAND_LENGTH, stdin) != NULL)
	{
		command[strcspn(command, "\n")] = '\0';

		if (strlen(command) == 0)
		{
			display_prompt();
			continue;
		}

		pid = fork();
		if (pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}

		else if (pid == 0)
		{
			execlp(command, command, NULL);

			perror("execlp");
			exit(EXIT_FAILURE);
		}

		else
		{
			waitpid(pid, &status, 0);
			if (WIFEXITED(status) && WEXITSTATUS(status) == 0)
			{
				display_prompt();
			}
			else
			{
				fprintf(stderr, "Error: Command execution failed.\n");
				display_prompt();
			}
		}
	}

	printf("\n");
	return (0);
}
