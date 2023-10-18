#include "main.h"
/**
 * error_msg - function to print error message
 * @command: invalid command
 * Return: error message
*/
void error_msg(char *command)
{
	char *message = malloc(100);

	_strcpy(message, "./hsh: 1: ");
	_strcat(message, command);
	_strcat(message, ": not found\n");
	write(STDERR_FILENO, message, strlen(message));
	free(message);
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
	char *fullPath;
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
			exit(*code);
		}
		else
			handle_exit_args(args[1]);
	}
	else
	{
		fullPath = findCommand(args[0], *code);
		if (is_valid(fullPath) == 0)
		{
			error_msg(fullPath);
			free(fullPath);
			exit(127);
		}
		args[0] = fullPath;
		pid = fork();
		if (pid == 0)
		{
			if (execve(args[0], args, environ) == -1)
			{
				free(fullPath);
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
	free(fullPath);
	free(message);
}
