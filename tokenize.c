#include "shell.h"
/** 
 * tokenize - function that splits the received command to arguments
 * @cmd: input received from get_cmd function
 * Return: 0 if sucess or -1 if fail
 */
int tokenize(char *cmd, )
{
  char *token = NULL;
  char *delim = " \t\n";
  size_t n = 0;


  /* tokenizee the input */
  token = strtok(cmd, delim);
  while (token != NULL)
    {
      n = strlen(token) + 1;
      char *buf = malloc(n);
      if (buf == NULL)
	{
	  perror("malloc error");
	  return -1;
	}
      /* using stringcopy to copy the input */
      strcpy(buf, token);
      free(buf);
      token = strtok(NULL, delim); /* get next token */
    }
  return (0);
}
