#include "shell.h"
/**
 * get_cmd - Function to read command
 * Return: input from user
 */
char get_cmd(void)
{
  size_t n = 0;
  char *cmd = NULL;
  ssize_t read;
  printf("$ ");
  read = getline(&cmd, &n, stdin);
  if (read == -1)
    {
      return (-1);
    }
  return (cmd);
}
