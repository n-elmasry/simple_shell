#include "main.h"

/**
* main - Entery point
* Return: 0 for success
*/
int main(void)
{
	int code = 0, check_mode = isatty(STDIN_FILENO);
	char *command;

	while (1)
	{
		if (check_mode)
			_putchar('$');

		command = readCommand();
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
