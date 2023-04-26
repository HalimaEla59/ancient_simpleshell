#include "shell.h"

/**
 * _strdup - duplicates string
 * @str: string
 * Return: result string
 */
char *_strdup(char *str)
{
	char *result;
	int i = 0;

	if (str == NULL)
		return (NULL);

	result = malloc(_strlen(str) + 1);
	if (result == NULL)
		return (NULL);

	while (str[i] != '\0')
	{
		result[i] = str[i];
		i++;
	}
	result[i] = '\0';

	return (result);
}

/**
 * _strcat - concatenates two strings
 * @dest: destination*
 * @src: source
 * Return: result string
 */
char *_strcat(char *dest, char *src)
{
	int i = 0;
	int j;

	while (dest[i] != '\0')
		i++;
	for (j = 0; src[j] != '\0'; j++)
		dest[i + j] = src[j];

	dest[i + j] = '\0';
	return (dest);
}


/**
 * get_argspath - gets the path of the arguments
 * @args: double pointer char arguments
 * @tokens: double pointer char tokens
 * Return: result or NULL
 */

char *get_argspath(char **args, char **tokens)
{
	int i, j, k = 0;
	char *result;
	char **tmp;


	struct stat status;

	for (i = 0; tokens[i]; i++)
	{
		result = malloc(60);
		_strcat(result, tokens[i]);
		_strcat(result, "/");
		_strcat(result, args[0]);
		if (stat(result, &status) == 0)
		{
			while (args[k])
				k++;
			tmp = malloc(sizeof(char *) * (k + 1));
			tmp[k] = NULL;
			tmp[0] = _strdup(result);

			for (j = 1; args[j]; j++)
				tmp[j] = _strdup(args[j]);
			exec_cmd(tmp);

			return (result);
		}
		free(result);
	}
	return (NULL);
}
