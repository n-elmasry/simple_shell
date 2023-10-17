#include "main.h"

/**
 * handle_exit_args - handels exit arguments
 * @status: status
 * Return: exit_status
*/
void handle_exit_args(char *status)
{
    int exit_status, i, len = 0;
    bool valid_status;
    valid_status = true;

    for (i = 0; status[i] != '\0'; i++)
    {
        if (status[i] < '0' || status[i] > '9')
            {
            valid_status = false;
            break;
        }
    }

    if (valid_status)
    {
        exit_status = atoi(status);

        if (exit_status < 0)
        {
            len = write(STDERR_FILENO, "./hsh: 1: exit: Illegal number: ", 32);
            len += write(STDERR_FILENO, status, strlen(status));
            len += write(STDERR_FILENO, "\n", 1);
            if (len < 0)
                perror("Error");
            exit(2);
        }
    }
    else
    {
        len = write(STDERR_FILENO, "./hsh: 1: exit: Illegal number: ", 32);
        len += write(STDERR_FILENO, status, strlen(status));
        len += write(STDERR_FILENO, "\n", 1);
        if (len < 0)
            perror("Error");
        exit(2);
    }
    exit(exit_status);
}
