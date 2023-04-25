#include "shell.h"
/**
 * exec_cmd - function to execute commands
 * @tokens: array of split input
 * @tok_cnt: number of elements in array tokens
 * Return: this is a void function
 */
void exec_cmd(char **tokens, int tok_cnt)
{
  pid_t pid = fork();/* initialize new process */
  if (pid == 0)
    {
      /*Start child process */
      char *envp[] = {NULL};
      if (execve(token[0], tokens, envp) == -1)
	{
	  perror("Error executing command");
	}
      exit(EXIT_FAILURE);
    }
  else if (pid < 0)
    {
      /*When procees fail to start */
      perror("Error starting process");
    }
  else
    {
      /* Parent Process */
      waitpid(pid, NULL, 0);
    }
}
