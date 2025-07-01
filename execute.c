#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include "simple_shell.h"

/**
* execute_child - execute command in child process
* @full_path: full path to executable
* @argv: command arguments
* @env: environment variables
* @cmd: original command name
*
* Return: void (function exits)
*/
void execute_child(char *full_path, char **argv, char **env, char *cmd)
{
	if (execve(full_path, argv, env) == -1)
	{
		perror(cmd);
		exit(127);
	}
}

/**
* wait_for_child - wait for child process and get exit status
* @full_path: full path to executable
* @cmd: original command name
*
* Return: exit status of child process
*/
int wait_for_child(char *full_path, char *cmd)
{
	int status;

	wait(&status);
	if (full_path != cmd)
		free(full_path);

	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	else
		return (-1);
}

/**
* execute - execute a command
* @cmd: the command to execute
* @env: environment variables
* @argv: command arguments
*
* Return: 0 on success, -1 on failure
*/
int execute(char *cmd, char **env, char **argv)
{
	pid_t pid;
	char *full_path;


	if (!cmd || strlen(cmd) == 0)
		return (0);

	if (!is_in_path(cmd, env))
	{
		fprintf(stderr, "%s: command not found\n", cmd);
		return (127);
	}

	full_path = get_full_path(cmd, env);
	if (!full_path)
		full_path = cmd;


	pid = fork();
	if (pid == -1)
	{
		perror("fork");

		if (full_path != cmd)
			free(full_path);

		return (-1);
	}
	else if (pid == 0)
	{

		execute_child(full_path, argv, env, cmd);
	}
	else
	{
		return (wait_for_child(full_path, cmd));
	}

	return (0);
}

/**
* is_in_path - checks whether command exists in $PATH or not
* @cmd: command name
* @env: environment variables
*
* Return: 1 if cmd exists in $PATH or 0 otherwise
*/
int is_in_path(char *cmd, char **env)
{
	char *path, *path_copy;
	char *dir, *dest;


	if (cmd == NULL)
		return (0);
	if (access(cmd, X_OK) == 0)
		return (1);

	path = get_env("PATH", env);
	if (!path)
		return (0);

	path_copy = strdup(path);
	dir = strtok(path_copy, ":");

	while (dir != NULL)
	{
		dest = malloc(strlen(dir) + strlen(cmd) + 2);
		sprintf(dest, "%s/%s", dir, cmd);

		if (access(dest, X_OK) == 0)
		{
			free(dest);
			free(path_copy);
			return (1);
		}

		free(dest);
		dir = strtok(NULL, ":");
	}

	free(path_copy);
	return (0);
}

/**
* get_full_path - gets the full path of a command
* @cmd: command name
* @env: environment variables
*
* Return: full path string or NULL if not found
*/
char *get_full_path(char *cmd, char **env)
{
	char *path, *path_copy, *dir;
	char *full_path;

	if (cmd == NULL)
		return (NULL);

	if (strchr(cmd, '/'))
		return (cmd);

	path = get_env("PATH", env);
	if (!path)
		return (NULL);

	path_copy = strdup(path);
	dir = strtok(path_copy, ":");

	while (dir != NULL)
	{
		full_path = malloc(strlen(dir) + strlen(cmd) + 2);
		if (!full_path)
		{
			free(path_copy);
			return (NULL);
		}

		sprintf(full_path, "%s/%s", dir, cmd);

		if (access(full_path, X_OK) == 0)
		{
			free(path_copy);
			return (full_path);
		}

		free(full_path);
		dir = strtok(NULL, ":");
	}

	free(path_copy);
	return (NULL);
}

