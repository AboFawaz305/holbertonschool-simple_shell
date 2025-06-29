#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include "simple_shell.h"

/**
 * execute - execute a command
 * @cmd: the command to execute
 * @env: environment variables
 * @argv: command arguments
 *
 * Return: 0 on success, -1 on failure
 * /
int execute(char *cmd, char **env, char **argv)
{
	pid_t pid;
	int status;
	char *cmd_argv[2];

	(void)argv;

	if (!cmd || strlen(cmd) == 0)
		return (0);


	cmd_argv[0] = cmd;
	cmd_argv[1] = NULL;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return (-1);
	}
	else if (pid == 0)
	{

		if (execve(cmd, cmd_argv, env) == -1)
		{
			perror(cmd);
			exit(127);
		}
	}
	else
	{

		wait(&status);
	}

	return (status);
}
*/

/**
 * is_in_path - checks whether command exists in $PATH or not
 * @cmd: command name
 *
 * Return: 1 if cmd exists in $PATH or 0 otherwise
 */
int is_in_path(char *cmd, char **env)
{
	char *path;

	if (cmd == NULL)
		return (0);
	if (access(cmd, X_OK) == 0)
		return (1);
	path = strtok(get_env("PATH", env), ":");
	while (path != NULL)
	{
		char *dest = malloc (sizeof (char) *(strlen(path) + 1 + strlen(cmd) + 1));
		dest[0] = '\0';
		strcat(dest, path);
		strcat(dest, "/");
		strcat(dest, cmd);
		if (access(dest, X_OK) == 0)
			return (1);
		path = strtok(NULL, ":");
		free (dest);
	}
	return (0);
}
