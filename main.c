#include "shell.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_COMMAND_LENGTH 100

/**
 * parse_input - function that parses the input
 * @input: input string
 * Return: char double pointer arguments
 */
char **parse_input(char *input)
{
	char **args;
	char *arg;
	int i = 0;

	args = malloc(sizeof(char *) * MAX_COMMAND_LENGTH);
	arg = strtok(input, " \n");

	while (arg != NULL)
	{
		args[i++] = arg;
		arg = strtok(NULL, " \n");
	}

	args[i] = NULL;
	return (args);
}

/**
 * print_prompt - function that prints the prompt
 *
 */
void print_prompt(void)
{
	printf("$ ");
}

/**
 * execute_command - function that executes the command
 * @command: string
 * @args: double pointer arguments
 * @envp: double pointer environ variable
 */
void execute_command(char *command, char **args, char **envp __attribute__ ((unused)))
{
	pid_t pid = fork();

	if (pid == 0)
	{
		/* child process */
		execvp(command, args);
		printf("%s: command not found\n", command);
		exit(1);
	}
	else if (pid < 0)
	{
		/* fork failed */
		printf("Fork failed\n");
		exit(1);
	}
	else
	{
		/* parent process */
		wait(NULL);
	}
}

/**
 * handle_input - function that handles the input
 * @input: given input string
 * @envp: double pointer environ variable
 */
void handle_input(char *input, char **envp)
{
	char *command;
	char **args;
	char **env;
	char *path, *dir, *command_path, *tmp;

	args = parse_input(input);
	command = args[0];
	if (_strcmp(command, "exit") == 0)
	{
		exit(0); /* exit the shell */
	} else if (_strcmp(command, "env") == 0)
	{
		for (env = envp; *env != 0; env++)
			printf("%s\n", *env); /* prints environ variable */
	} else /* check if command in PATH */
	{
		path = getenvv(envp, "PATH");
		dir = strtok(path, ":");
		command_path = NULL;
		while (dir != NULL)
		{
			tmp = malloc(_strlen(dir) + _strlen(command) + 2);
			sprintf(tmp, "%s/%s", dir, command);
			if (access(tmp, F_OK) == 0)
			{
				command_path = tmp;
				break;
			}
			dir = strtok(NULL, ":");
			free(tmp);
		}
		if (command_path != NULL)
			execute_command(command_path, args, envp);
		else
			printf("%s: command not found\n", command);
	}
	free(args);
}

/**
 * main - main entry
 * @argc: int
 * @argv: double pointer
 * @envp: double pointer
 * Return: 0
 */
int main(int argc __attribute__ ((unused)), char **envp)
{
	char input[MAX_COMMAND_LENGTH];

	while (1)
	{
		print_prompt();

		if (fgets(input, MAX_COMMAND_LENGTH, stdin) == NULL)
			exit(0); /* end of file */

		handle_input(input, envp);
	}

	return (0);
}
