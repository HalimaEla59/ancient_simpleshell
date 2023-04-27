#include "shell.h"

/**
 * _atoi - converts string to int
 * @s: tring
 * Return: int
 */

int _atoi(char *s)
{
	int sign = 1;
	int i = 0;
	int integer = 0;

	while (!((s[i] >= '0') && (s[i] <= '9')) && (s[i] != '\0'))
	{
		if (s[i] == '-')
			sign = sign * (-1);
		i++;
	}
	while ((s[i] >= '0') && (s[i] <= '9'))
	{
		integer = (integer * 10) + (sign * (s[i] - '0'));
		i++;
	}
	return (integer);
}
