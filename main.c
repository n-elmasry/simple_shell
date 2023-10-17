#include "main.h"

/**
* main - Entery point
* Return: 0 for success
*/
int main(void)
{
	int check_mode = isatty(STDIN_FILENO), code = 0;
	char *command;

	while (1)
	{
		if (check_mode)
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
