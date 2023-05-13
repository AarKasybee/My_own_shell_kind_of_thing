#include "headers.h"

/**
 * main - Entry point to the shell program
 *
 * Return: success returns 0
 */
int main(void)
{
	char input[MAX_COMMAND_LENGTH];
	char *command[MAX_COMMAND_LENGTH];
	char **path;
	char *token;
	int i;

	path = get_path();

	while (1)
	{
		printf("#cisfun$ ");
		fflush(stdout); /*flush the output buffer*/
		if (fgets(input, MAX_COMMAND_LENGTH, stdin) == NULL) /**EOF*/
		{
			printf("\n");
			exit(0);
		}
		/* remove the newline character at the end of the command*/
		input[strcspn(input, "\n")] = '\0';
		i = 0;
		token = strtok(input, " ");
		while (token != NULL && i < MAX_COMMAND_LENGTH - 1)
		{
			command[i] = token;
			i++;
			token = strtok(NULL, " ");
		}
		command[i] = NULL; /* terminate the array with a NULL pointer */
		fork_new_process(command, path);
	}
	return (0);
}
