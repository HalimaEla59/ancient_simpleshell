#include "shell.h"

/**
 * main - entry point
 * Return: 0 on success
 */
/*int main(int ac, char **av, char **env)
{
  char *input = NULL;
  char **args = NULL;
  (void)ac;
(void)av;
  while(1)
    {
      /*display prompt */
      /*     _prompt();
      /*Get input */
/*    input = get_cmd();
      if (cmd == NULL)
	{
	  break;
	}
      args = tokenize(cmd);
      /*tokenize*/
      /*   tok_cnt = tokenize(input, &tokens);
 */     /*Execute command */
/*if (args == NULL || args[0] == NULL)
		{
	  free(args);
	  continue;
	}
      if (_strcmp(args[0], "exit" == 0)
	{
	  sh_exit();
	  break;
	}
	status = exec_cmd(args);
      /* free input */
      /*    free(args);
    }
  return (0);
}*/
int main(void)
{
	char **argv, *path, *val, *buff = NULL;
	size_t size = 0;
	ssize_t gl = 0;
	list_path *head = '\0';
	void (*fct)(char **);

	signal(SIGINT, sig_handler);
	while (gl != EOF)
	{
		_isatty();
		gl = getline(&buff, &size, stdin);
		_EOF(gl, buff);
		argv = tokenize2(buff, " \n");
		if (!argv || !argv[0])
			exec_cmd(argv);
		else
		{
			val = getenvv("PATH");
			head = link_path(val);
			path = look_for(argv[0], head);
			fct = checkcmd(argv);
			if (fct)
			{
				free(buff);
				fct(argv);
			}
			else if (!path)
				exec_cmd(argv);
			else if (path)
			{
				free(argv[0]);
				argv[0] = path;
				exec_cmd(argv);
			}
		}
	}
	free_list(head);
	free_argv(argv);
	free(buff);
	return (0);
}
