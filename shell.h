#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

#define MAX_ARGS 10
#define MAX_LEGTH 100

char *get_cmd(void);
void exec_cmd(char **tokens, int tok_cnt);
int tokenize(char *cmd, char **tokens);
/* get_path functions */
char **tokenize2(char *path);
char *check_eq(char *str);
int equals(char *str1, char *str2);
char *getenvv(char **environ, char *name);
char **get_path(char **environ);
/* other used functions */
int _putchar(char c);
int _strlen(char *s);

#endif
