#include "headers.h"

/**
 * get_path - retrieves the directories in the PATH environment variable
 *
 * Return: an array of paths
 */
char **get_path()
{
	char *path_string = getenv("PATH");
	char **path = malloc((MAX_COMMAND_LENGTH + 1) * sizeof(char *));
	char *token;
	int i = 0;

	if (path_string == NULL)
	{
		perror("getenv failed");
		exit(1);
	}
	token = strtok(path_string, ":");
	while (token != NULL)
	{
		path[i] = token;
		i++;
		token = strtok(NULL, ":");
	}
	path[i] = NULL;
	return (path);
}

