#include "shell.h"

/**
 * tokenize - function that splits the received command to arguments
 * @cmd: input received from get_cmd function
 * Return: tokens
 */
char **tokenize(char *cmd)
{
char **token;
char *delim = " \t\n";
char *buf;
size_t n = 0;
int i = 0;

token = malloc(sizeof(char *) * 1024);
if (token == NULL)
	exit(99);

/* tokenizee the input */
token[i] = strtok(cmd, delim);
i++;

while (token[i] != NULL)
{
	n = strlen(token[i]) + 1;
	buf = malloc(n);
	if (buf == NULL)
	{
		perror("malloc error");
		exit(98);
	}
	/* using stringcopy to copy the input */
	strcpy(buf, token[i]);
	free(buf);
	/* get next token */
	i++;
}
return (token);
}