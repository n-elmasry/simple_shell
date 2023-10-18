#include "main.h"

/**
 * is_valid - a function checks if the command is valid
 * @path: path to check in
 * Return: 0 for success
*/

int is_valid(char *path)
{
	if (access(path, X_OK) == 0)
	{
		return (1);
	}
	return (0);
}
/**
 * readCommand - a functopn reads the inputted command
 * Return: command
*/
char *readCommand()
{
	size_t n = 0;
	ssize_t read;
	char *command = NULL;

	read = getline(&command, &n, stdin);
	if (read == -1)
	{
		free(command);
		exit(0);
	}
	(command)[strcspn(command, "\n")] = '\0';
	return (command);
}
