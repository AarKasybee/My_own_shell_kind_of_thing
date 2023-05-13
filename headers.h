#ifndef HEADERS_H
#define HEADERS_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <signal.h>
#include <stddef.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_PATH_LENGTH 100

size_t _strcspn(const char *str1, const char *str2);
void _puts(char *str);
int _putchar(char c);

extern char **environ;
void exit_func(char **command);
void env_func(char **command);

void fork_new_process(char **command, char **path);

char **get_path();
/*ssize_t _getline(char **restrict line_ptr, size_t *restrict n, FILE * restrict stream);*/
#endif
