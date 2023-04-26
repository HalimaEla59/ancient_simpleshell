#include "shell.h"
/**
 * main - entry point
 * @argc: argc unused
 * @argv: argument array
 * @environ: environ variable
 * Return: 0 on success
 */

int main(int argc __attribute__ ((unused)), char **argv, char **environ)
{
char *input = NULL;
char **tokens;
char *delimiter = "\t \a\n";
char *cmd;

tokens = get_path(environ);
signal(SIGINT, SIG_IGN);
while (1)
{
/*Grab input */
input = get_cmd();
if (input == NULL)
{
	_putchar('\n');
	break;
}

argv = tokenize2(input, delimiter);
cmd = get_argspath(argv, tokens);

if (cmd == NULL)
	exec_cmd(argv);

free(input);
free(argv);
free(cmd);
}
return (0);
}
