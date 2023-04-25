#include "shell.h"
/**
 * tokenize - function that splits the received command to arguments
 * @cmd: input received from get_cmd function
 * @tokens: array to hold the input after spliting
 * Return: number of tokens obtained after splitting
 */
int tokenize(char *cmd, char **tokens)
{
char *token;
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
 * tokenize2 - splits the recieved path
 * @path: string
 * Return: char double pointer token
 */
char **tokenize2(char *path)
{
	char **token;
	char *delimiter;
	int i = 1;

	delimiter = ":";
	token = malloc(sizeof(char *) * 1024);
	if (token == NULL)
		exit(99);

	token[0] = strtok(path, delimiter);
	while (token[i] != NULL)
	{
		token[i] = strtok(NULL, delimiter);
		i++;
	}
	return (token);
}
