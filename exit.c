#include "headers.h"

/**
 * exit_func - This function exits the terminal or the shell
 * @command: user input command
 *
 * Return: nothing
 */
void exit_func(char **command)
{
	if (strcmp(command[0], "exit") == 0) /* handle exit command */
	{
		exit(0);
	}
}

