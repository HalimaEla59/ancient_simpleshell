#include "shell.h"
/**
 * tokenize - function that splits the received command to arguments
 * @cmd: input received from get_cmd function
 * @tokens: array to hold the input after spliting
 * Return: number of tokens obtained after splitting
 */
int tokenize(char *cmd, char **tokens)
{
char *delim = " \t\n";
int tok_cnt = 0;
char *token = strtok(cmd, delim);

/* tokenizee the input */
while (token != NULL && tok_cnt < MAX_ARGS)
{
tokens[tok_cnt++] = token;
token = strtok(NULL, delim);
}
return (tok_cnt);
}

/**
 * tokenize2 - splits the recieved string
 * @s: string
 * @delimiter: delimiter string
 * Return: char double pointer array
 */
char **tokenize2(char *s, const char *delimiter)
{
	char **arr;
	int i, j;
	char *token, *tmp;

	tmp = malloc(_strlen(s) + 1);
	if (tmp == NULL)
	{
		perror(getenvv("_"));
		return (NULL);
	}

	i = 0;
	while (s[i])
	{
		tmp[i] = s[i];
		i++;
	}
	tmp[i] = '\0';

	token = strtok(tmp, delimiter);
	arr = malloc(sizeof(char *) * 2);
	arr[0] = _strdup(token);

	i = 1;
	j = 3;
	while (token)
	{
		token = strtok(NULL, delimiter);
		arr = _realloc(arr, (sizeof(char *) * (j - 1)), (sizeof(char *) * j));
		arr[i] = _strdup(token);
		i++;
		j++;
	}
	free(tmp);
	return (arr);
}
