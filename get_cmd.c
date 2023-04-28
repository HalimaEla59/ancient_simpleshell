#include "shell.h"
/**
 * get_cmd - Function to read command
 *@bufsize: this is a pointer to the input
 * Return: input from user
 */
char *get_cmd(size_t *bufsize)
{
size_t n = 0;
char *cmd = NULL;
int len;
ssize_t read;
read = getline(&cmd, bufsize, stdin);
if (read == -1)
{
  if (feof(stdin))
    {
      free(cmd);
      _putchar("\n");
      return (NULL);
    }
perror("Could not read input");
/*free(cmd);*/
exit(EXIT_FAILURE);
}
 if(cmd[read - 1] == '\n)
   {
     cmd[read -1] = '\0';
   }
   /*len = _strlen(cmd);
cmd[len - 1] = '\0';*/

return (cmd);
}
