#include "shell.h"
/**
 * exec_cmd - function to execute commands
 * @args: array of arguments
 * Return: this is a void function
 */

void exec_cmd(char **tokens)
{
	pid_t pid;
	int status;
	if (tokens[0] == NULL)
	  {
	    return (0);
	  }

	pid = fork();
	if (pid == 0)
	{
		execve(tokens[0], tokens, environ);
		perror(tokens[0]);
		exit(EXIT_FAILURE);
	}
	if (pid == -1)
	{
		perror(getenvv("_"));
	}
	else
	{
		/* Parent Process */
	  wait(&status); /* waitpid(pid, NULL, 0) */
	}
}
