#include "shell.h"
/**
 * main - entry point
 * Return: 0 on success
 */
int main(void)
{
char *input = NULL;
char *tokens[MAX_ARGS];
int tok_cnt;
while (1)
{
/*Grab input */
input = get_cmd();
if (input == NULL)
{
printf("\n");
break;
}
/* Let's tokenize the input */
tok_cnt = tokenize(input, tokens);
/* Execute command */
if (tok_cnt > 0)
{
exec_cmd(tokens, tok_cnt);
}
/*free input */
free(input);
input = NULL;
}
return (0);
}
