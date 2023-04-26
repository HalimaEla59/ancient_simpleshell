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
/*ssize_t read;*/

_putchar('$');
_putchar(' ');

if (getline(&cmd, &n, stdin) == -1)
{
free(cmd);
	exit(-1);
}
len = _strlen(cmd);
cmd[len - 1] = '\0';

return (cmd);
}
