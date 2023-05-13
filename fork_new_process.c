#include "headers.h"

void call_parent(char **command, pid_t pid);

/**
 * fork_new_process - forks a new process within the parent process
 *@command: an array of user input characters in the user command
 *@path: an array of paths to search for executable programs
 *
 * Return: void
 */
void fork_new_process(char **command, char **path)
{
	pid_t pid;

	exit_func(command);
	env_func(command);
	pid = fork();

	if (pid == -1)
	{
		perror("fork failed");
	}
	else if (pid == 0) /* child process*/
	{
		char executable_path[MAX_PATH_LENGTH];
		int i;

		execve(command[0], command, NULL);
		for (i = 0; path[i] != NULL; i++)
		{
			snprintf(executable_path, MAX_PATH_LENGTH, "%s/%s", path[i], command[0]);
			execve(executable_path, command, NULL);
		}
		perror("./shell: "); /*if execve returns, it must have failed*/
		exit(1);
	}
	else /*parent process*/
	{
		call_parent(command, pid);
	}
}

/**
 * call_parent - start the parent process
 * @command: user input command
 * @pid: process id
 * Return: void
 */
void call_parent(char **command, pid_t pid)
{
	int status;

	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
	{
		int exit_status = WEXITSTATUS(status);

		if (exit_status != 0)
		{
			printf("Command '%s' failed with exit status %d\n",
				command[0], exit_status);
		}
	}
	else if (WIFSIGNALED(status))
	{
		int signal_number = WTERMSIG(status);

		printf("Command '%s' was terminated by signal %d\n",
				  command[0], signal_number);
	}
}
