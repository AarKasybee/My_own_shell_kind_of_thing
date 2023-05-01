#include "others.h"

/**
 * fork_new_process - forks a new process
 * @command: input from user
 *
 * Return: void
 */
void fork_new_process(char *command)
{
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("fork failed");
	}
	else if (pid == 0) /* child process*/
	{
		/* split the command string by spaces */
		char *argv[256] = { NULL };
		char *token;
		int i = 0;

		token = strtok(command, " ");
		while (token != NULL)
		{
			argv[i++] = token;
			token = strtok(NULL, " ");
		}

		execve(argv[0], argv, NULL);
		perror("./shell"); /*if execve returns, it must have failed*/
		exit(1);
	}
	else /*parent process*/
	{
		int status;

		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
		{
			int exit_status = WEXITSTATUS(status);

			if (exit_status != 0)
			{
				/*do nothing*/
			}
		}
	}
}

/**
 * main - Entry point to the shell program
 *
 * Return: success returns 0
 */
int main(void)
{
	char *command = NULL;
	size_t length = 0;

	while (1)
	{
		_puts("#cisfun$ ");
		fflush(stdout); /* flush the output buffer */
		if (getline(&command, &length, stdin) == -1)
		{
			_puts("\n");
			free(command);
			exit(0);
		}

		/* remove the newline character at the end of the command*/
		command[_strcspn(command, "\n")] = 0;

		/* fork a new process*/
		fork_new_process(command);
	}

	free(command);
	return (0);
}
