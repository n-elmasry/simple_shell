#include "main.h"
/**
 * findCommand - a function search for the command in a given path
 * @command: command to search for
 * @code: code to exit
 * Return: command result
*/
char *findCommand(char *command, int code)
{
	int i = 0;
	char *fullPath = malloc(100), *path;
	const char *searchDirectories[] = {
		"/bin", "/usr/bin", "/usr/local/bin", NULL};

	for (i = 0; searchDirectories[i] != NULL; i++)
	{
		_strcpy(fullPath, searchDirectories[i]);
		_strcat(fullPath, "/");
		_strcat(fullPath, command);

		if (access(fullPath, X_OK) == 0)
		{
			return (fullPath);
		}
	}
	free(fullPath);
	path = malloc(100);
	_strcpy(path, command);
	if (_strcmp(path, "exit") == 0)
		exit(code);

	return (path);
}
