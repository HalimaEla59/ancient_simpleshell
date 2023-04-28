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

/**
 * setenvv - sets a new environment or modify one
 * @argv: array of arguments
 */
void setenvv(char **argv)
{
	int i, j, k;

	if (!argv[1] || !argv[2])
	{
		perror(getenvv("_"));
		return;
	}
	for (i = 0; environ[i]; i++)
	{
		j = 0;
		if (argv[1][j] == environ[i][j])
		{
			while (argv[1][j])
			{
				if (argv[1][j] != environ[i][j])
					break;
				j++;
			}
			if (argv[1][j] == '\0')
			{
				k = 0;
				while (argv[2][k])
				{
					environ[i][j + k + 1] = argv[2][k];
					k++;
				}
				environ[i][j + k + 1] = '\0';
				return;
			}
		}
	}
	if (!environ[i])
	{
		environ[i] = _strcat3(argv[1], "=", argv[2]);
		environ[i + 1] = '\0';
	}
}

/**
 * unsetenvv - unsets environment variable
 * @argv: array arguments
 */
void unsetenvv(char **argv)
{
	int i, j;

	if (!argv[1])
	{
		perror(getenvv("_"));
		return;
	}
	for (i = 0; environ[i]; i++)
	{
		j = 0;
		if (argv[1][j] == environ[i][j])
		{
			while (argv[1][j])
			{
				if (argv[1][j] != environ[i][j])
					break;
				j++;
			}
			if (argv[1][j] == '\0')
			{
				free(environ[i]);
				environ[i] = environ[i + 1];
				while (environ[i])
				{
					environ[i] = environ[i + 1];
					i++;
				}
				return;
			}
		}
	}
}

