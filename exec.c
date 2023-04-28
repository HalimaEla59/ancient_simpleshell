#include "shell.h"
/**
 * exec_cmd - function to execute commands
 * @args: array of arguments
 * Return: this is a void function
 */

void exec_cmd(char **args)
{
	pid_t pid;
	int status;
	if (args[0] == NULL)
	  {
	    return (0);
	  }

	pid = fork();
	if (pid == 0)
	{
		execve(args[0], args, environ);
		perror(args[0]);
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
