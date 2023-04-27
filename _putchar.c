#include "shell.h"

/**
 * _putchar - writes a given character
 * @c: the given character
 * Return: 1 or -1
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
