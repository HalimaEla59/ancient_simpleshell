#include "shell.h"
/**
 * equals - checks if 2 strings are equals
 * @str1: first string
 * @str2: second string
 * Return: 1 or 0
 */
int equals(char *str1, char *str2)
{
int i = 0;
while (str1[i] != '\0' && str2[i] != '\0')
{
if (str1[i] != str2[i])
return (0);
i++;
}
return (1);
}
/**
 * check_eq - checks for the = symbole
 * @str: string
 * Return: string
 */
char *check_eq(char *str)
{
int i = 0;
while (str[i] != '=')
i++;
return (str + i + 1);
}

/**
 * getenvv - gets the name from the environ
 * @name: string
 * Return: string of value or NULL
 */
char *getenvv(const char *name)
{
	int i, j;
	char *result;

	if (!name)
		return (NULL);

	for (i = 0; environ[i]; i++)
	{
		j = 0;
		if (name[j] == environ[i][j])
		{
			while (name[j])
			{
				if (name[j] != environ[i][j])
					break;
				j++;
			}
			if (name[j] == '\0')
			{
				result = (environ[i] + j + 1);
				return (result);
			}
		}
	}
	return (0);
}

/**
 * get_path - function that gets the path
 * @environ: pointer to pointer environ
 * Return: the path
 */
char **get_path(char **environ __attribute__ ((unused)))
{
char **token;
char *path;
path = getenvv("PATH"); /* works like getenv() */
token = tokenize2(path, ":");
return (token);
}
