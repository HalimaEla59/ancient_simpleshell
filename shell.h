#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

char get_cmd(char *cmd);
int my_shell(void);

/* get_path.c functions */
char **tokenize(char *cmd);
char *check_eq(char *str);
int equals(char *str1, char *str2);
char *getenvv(char **environ, char *name);
char **get_path(char **environ);

#endif
