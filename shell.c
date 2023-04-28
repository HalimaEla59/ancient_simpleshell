#include "shell.h"

/**
 * main - entry point
 * Return: 0 on success
 */
int main(void)
{
  char *input = NULL;
  char **tokens = NULL;
  int tok_cnt;

  while(1)
    {
      /*Get input */
      input = get_cmd();
      /*tokenize*/
      tok_cnt = tokenize(input, &tokens);
      /*Execute command */
      if (tok_cnt > 0)
	{
	  exec_cmd(tokens, tok_cnt);
	}
      /* free input */
      free(input);
      input = NULL;
    }
  return (0);
}
/*int main(void)
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
}*/
