#include "main.h"
/**
 * error_msg - function to print error message
 * @command: invalid command
 * Return: error message
*/
char *error_msg(char *command)
{
	char *message = malloc(100);

	_strcpy(message, "./hsh: 1: ");
	_strcat(message, command);
	_strcat(message, ": not found\n");
	write(STDERR_FILENO, message, strlen(message));

	return (message);
}
/**
 * executeCommand - a function is responsible for excutng a command
 * @command: command to be excecuted
 * @code: exit
*/
void executeCommand(char *command, int *code)
{
	char *args[100], *message = NULL;
	int i = 0, flag;
	char *token = strtok(command, " \t\n");
	pid_t pid;

	while (token)
	{
		args[i] = token;
		token = strtok(NULL, " ");
		i++;
	}
	args[i] = NULL;
	if (i == 0)
		return;
	if (strcmp(args[0], "exit") == 0)
	{
		if (i == 1)
		{
			free(command);
			exit(*code);
		}
		else
			handle_exit_args(args[1]);
	}
	else
	{
		args[0] = findCommand(args[0], *code);
		if (is_valid(args[0]) == 0)
		{
			message = error_msg(args[0]);
			free(message);
			exit(127);
		}
		pid = fork();
		if (pid == 0)
		{
			if (execve(args[0], args, environ) == -1)
			{
				perror("Error");
				exit(2);
			}
		}
		else
		{
			wait(&flag);
			*code = WEXITSTATUS(flag);
		}
	}
	free(message);
}
