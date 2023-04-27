#include "shell.h"

/**
 * _exits - exits the shell
 * @argv: array of arguments
 */

void _exits(char **argv)
{
	int i, n;

	if (argv[1])
	{
		n = _atoi(argv[1]);
		if (n < 0)
			n = 2;
		free_argv(argv);
		exit(n);
	}
	for (i = 0; argv[i]; i++)
		free(argv[i]);
	free(argv);
	exit(0);
}

/**
 * env - prints the environment
 * @argv: array of arguments
 */
void env(char **argv __attribute__ ((unused)))
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		_puts(environ[i]);
		_puts("\n");
	}
}
