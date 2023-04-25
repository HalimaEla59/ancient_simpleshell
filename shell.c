#include "shell.h"

/**
 * main - entry point
 * Return: 0 on success
 */
int main(void)
{
  char *input = NULL;
  char *tokens[MAX_ARGS];
  int num_tokens;
  while (1)
    {
      /*Grab input */
      input = get_cmd();
      /* Let's tokenize the input */
      num_tokens = tokenize(input, tokens);
      /* Execute command */
      if (num_tokens > 0)
	{
      exec_cmd(tokens, num_tokens);
	}
      /*free input */
      free(input);
      input = NULL;
    }
  return (0);
}
