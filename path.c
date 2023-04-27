#include "shell.h"

/*
 * add_node_end - adds new node at the end of list
 * @head: double pointer to head of list
 * @str: string to add
 * Return: @ to head of new list
 */

list_path *add_node_end(list_path **head, char *str)
{
	list_path *temp;
	list_path *newlist;

	newlist = malloc(sizeof(list_path));
	if (!newlist || !str)
		return (NULL);

	newlist->dir = str;
	newlist->next = '\0';
	if (!*head)
	{
		*head = newlist;
	}
	else
	{
		temp = *head;
		while (temp->next)
			temp = temp->next;

		temp->next = newlist;
	}
	return (*head);
}

/**
 * link_path - creates a linkes list for path dir
 * @path: string
 * Return: pointer to the linked list
 */

list_path *link_path(char *path)
{
	list_path *head;
	char *token, *temp;

	head = '\0';
	temp = _strdup(path);
	token = strtok(temp, ":");

	while (token)
	{
		head = add_node_end(&head, token);
		token = strtok(NULL, ":");
	}
	return (head);
}
