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
/* tokenizee the input */
while (token != NULL && tok_cnt < MAX_ARGS)
{
tokens[tok_cnt++] = token;
token = strtok(NULL, delim);
}
return (tok_cnt);
}
