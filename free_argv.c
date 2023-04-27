#include "shell.h"

/**
 * free_argv - frees array of of arguments
 * @argv: array of arguments
 */

void free_argv(char **argv)
{
	int i;

	for (i = 0; argv[i]; i++)
		free(argv[i]);
	free(argv);
}

/**
 * free_list - frees list
 * @head: head of list
 */
void free_list(list_path *head)
{
	list_path *temp;

	while (head)
	{
		temp = head->next;
		free(head->dir);
		free(head);
		head = temp;
	}
}
