#include "shell.h"
/**
 * get_cmd - Function to read command
 * Return: input from user
 */
char *get_cmd(void)
{
size_t n = 0;
char *cmd = NULL;
ssize_t read;
printf("$ ");
getline(&cmd, &n, stdin);
return (cmd);
}
