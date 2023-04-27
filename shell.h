#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <limits.h>
#include <signal.h>

#define MAX_ARGS 10
#define MAX_LEGTH 100

char *get_cmd(void);
void exec_cmd(char **tokens);
int tokenize(char *cmd, char **tokens);
char *get_argspath(char **args, char **tokens);
/* get_path functions */
char **tokenize2(char *s, const char *delimiter);
char *check_eq(char *str);
int equals(char *str1, char *str2);
char *getenvv(const char *name);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char **get_path(char **environ);
/* string manipulation functions */
int _putchar(char c);
int _strlen(char *s);
char *_strdup(char *str);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);

extern char **environ;

#endif
