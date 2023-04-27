#include "shell.h"

/**
 * free_argv - frees array of of arguments
 * @argv: array of arguments
 */

void free_argv(char **argv)
{
	int i;

	for (i = 0; argv[i]; i++)
		free(argv[i]);
	free(argv);
}
