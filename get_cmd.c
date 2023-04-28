#include "shell.h"
/**
 * get_cmd - Function to read command
 * Return: input from user
 */
char *get_cmd(void)
{
size_t n = 0;
char *cmd = NULL;
int len;
char *read;
/*ssize_t read;*/
_putchar("$ ");
 read = getline(cmd, &n, stdin);
if (read == -1)
{
perror("Could not read input");
free(cmd);
exit(-1);
}
len = _strlen(cmd);
cmd[len - 1] = '\0';

return (cmd);
}
