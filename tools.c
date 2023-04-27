#include "shell.h"

/**
 * sig_handler - checks if Ctrl + C are pressed
 * @sig_num: int
 */
void sig_handler(int sig_num)
{
	if (sig_num == SIGINT)
		_puts("\n#cisfun$ ");
}

/**
 * _isatty - verify terminal
 */
void _isatty(void)
{
	if (isatty(STDIN_FILENO))
		_puts("#cisfun$ ");
}

/**
 * _EOF - handles the end of files
 * @gl: value of getline func
 * @buff: buffer
 */
void _EOF(int gl, char *buff)
{
	(void)buff;

	if (gl == -1)
	{
		if (isatty(STDIN_FILENO))
		{
			_puts("\n");
			free(buff);
		}
		exit(0);
	}
}
