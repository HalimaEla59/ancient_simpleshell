#include "shell.h"
/**
 * main - entry point
 * @argc: argc unused
 * @environ: environ variable
 * Return: 0 on success
 */
int main(int argc __attribute__ ((unused)), char **environ)
{
char *input = NULL;
char **tokens;
int tok_cnt;

tokens = get_path(environ);
while (1)
{
/*Grab input */
input = get_cmd();

if (input == NULL)
{
_putchar('\n');
break;
}

/* Let's tokenize the input */
tok_cnt = tokenize(input, tokens);
/* Execute command */
if (tok_cnt > 0)
{
exec_cmd(tokens);
}

/*free input */
free(input);
input = NULL;
}

return (0);
}
