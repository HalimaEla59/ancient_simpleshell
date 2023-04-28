#include "shell.h"
/**
 * get_cmd - Function to read command
 *@bufsize: this is a pointer to the input
 * Return: input from user
 */
char *get_cmd(char *cmd)
{
size_t n = 0;
char *cmd = NULL;
int len;
ssize_t read;
read = getline(&cmd, bufsize, stdin);
if (read == -1)
{
perror("Could not read input");
/*free(cmd);*/
exit(EXIT_FAILURE);
}
len = _strlen(cmd);
cmd[len - 1] = '\0';

return (cmd);
}
