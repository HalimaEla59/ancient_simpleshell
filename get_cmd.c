#include "main.h"
/**
 * get_cmd - Function to read command
 * cmd: the command to be received
 * Return: void
 */
void get_cmd()
{
  char *cmd = NULL;
  size_t n = 0;
  printf("$ ");
  if (getline(&cmd, &n, &stdin))
    {
      return (-1);
    }
}
