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
 * getenvv - gets the path in the environ
 * @environ: global variable
 * @name: string
 * Return: string of value or NULL
 */
char *getenvv(char **environ, char *name)
{
int i, j;
char *N, *M;
for (i = 0; environ[i]; i++)
{
N = malloc(1024);
for (j = 0; environ[i][j] != '='; j++)
N[j] = environ[i][j];
if (equals(name, N))
{
M = check_eq(environ[i]);
free(name);
return (M);
}
free(name);
}
return (NULL);
}
/**
 * get_path - function that gets the path
 * @environ: pointer to pointer environ
 * Return: the path
 */
char **get_path(char **environ)
{
char **token;
char *path;
path = getenvv(environ, "PATH"); /* works like getenv() */
token = tokenize(path);
return (token);
}
