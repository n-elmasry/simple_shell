#include "main.h"

/**
* main - Entery point
* Return: 0 for success
*/
int main(void)
{
	int code = 0;
	char *command;

	while (1)
	{
		_putchar('$');

		command = NULL;
		readCommand(&command);
		if (_strcmp(command, "exit") == 0)
		{
			free(command);
			exit(code);
		}

		executeCommand(command, &code);
		free(command);
	}
	exit(code);
	return (0);
}
