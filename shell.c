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
char **tokens, **env, *cmd;
char *delimiter = "\t \a\n";

tokens = get_path(environ);
signal(SIGINT, SIG_IGN);
while (1)
{
	/*_putchar($);*/
	/*_putchar( );*/

input = get_cmd(); /* grab input */
if (input == NULL)
{
	_putchar('\n');
	break;
}

argv = tokenize2(input, delimiter);
cmd = get_argspath(argv, tokens);
if (_strcmp(argv[0], "exit") == 0)
{
	exit(0); /* exit shell */
}
if (_strcmp(argv[0], "env") == 0)
{
	for (env = environ; *env != 0; env++)
		printf("%s\n", *env); /* print env */
}
if (cmd == NULL)
	exec_cmd(argv);

free(input);
free(argv);
free(cmd);
}
return (0);
i}
