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

/**
 * _strcat3 - concatenates three strings
 * @s1: first string
 * @s2: second string
 * @s3: third string
 * Return: new string
 */
char *_strcat3(char *s1, char *s2, char *s3)
{
	char *newstr;
	int len1, len2, len3;
	int i, j;

	len1 = _strlen(s1);
	len2 = _strlen(s2);
	len3 = _strlen(s3);
	newstr = malloc(len1 + len2 + len3 + 1);
	if (!newstr)
		return (NULL);

	for (i = 0; s1[i]; i++)
		newstr[i] = s1[i];
	j = i;
	for (i = 0; s2[i]; i++)
		newstr[j + i] = s2[i];
	j = j + i;
	for (i = 0; s3[i]; i++)
		newstr[j + i] = s3[i];
	j = j + i;
	newstr[j] = '\0';
	return (newstr);
}

/**
 * look_for - looks for a pathname in a filename
 * @filename: name of file
 * @head: head of linked list
 * Return: NULL or pathname
 */

char *look_for(char *filename, list_path *head)
{
	struct stat st;
	char *str;
	list_path *temp = head;

	while (temp)
	{
		str = _strcat3(temp->dir, "/", filename);
		if (stat(str, &st) == 0)
			return (str);

		free(str);
		temp = temp->next;
	}
	return (NULL);
}

/**
 * checkcmd - checkes for the existance of cmd
 * @argv: array of arguments
 * Return: pointer to void func(char **argv)
 */
void(*checkcmd(char **argv))(char **argv)
{
	int i, j;

	mycmd C[] = {
		{"exit", _exit},
		{"env", env},
		{NULL, NULL}
	};

	for (i = 0; C[i].name; i++)
	{
		j = 0;
		if (C[i].name[j] == argv[0][j])
		{
			for (j = 0, argv[0][j]; j++)
			{
				if (C[i].name[j] != argv[0][j])
					break;
			}
			if (!argv[0][j])
				return (C[i].func);
		}
	}
	return (0);
}

