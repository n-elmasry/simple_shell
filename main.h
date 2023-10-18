#ifndef MAIN_H
#define MAIN_H
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <errno.h>
#include <stdbool.h>
#include <ctype.h>
#include <stddef.h>
#define _POSIX_C_SOURCE 200809L
#define READ_SIZE 1024

extern char **environ;

int _putchar(char c);
char *_strcpy(char *dest, const char *src);
char *_strcat(char *dest, const char *src);
char *_strdup(const char *str);
int _strcmp(char *s1, char *s2);
char *error_msg(char *command);
void handle_exit_args(char *status);
char *findCommand(char *command, int code);
int is_valid(char *path);
char *readCommand();
void executeCommand(char *command, int *code);

#endif
