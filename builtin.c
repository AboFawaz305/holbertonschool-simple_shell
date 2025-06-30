#include "simple_shell.h"
#include <string.h>
#include <stdlib.h>

/**
 * is_builtin - returns with cmd is a builtin command or not
 * @cmd: a command name
 *
 * Return: 1 if cmd is a builtin or 0 otherwise
 */
int is_builtin(char *cmd)
{
	(void) cmd;
	return (0);
}

/**
 * _atoi - convert s to an integer
 * @s: a null terminated string.
 *
 * Return: s converted to an int.
 */
int _atoi(char *s)
{
	int r = 0;
	int size = strlen(s) - 1;
	int b = 1;

	while (size >= 0)
	{
		r += (s[size] - '0') * b;
		b *= 10;
		size--;
	}

	return (r);
}

/**
 * exit_shell - exit from the shell
 * @args: exit arguments
 * @env: environment variables
 *
 * Description: by default the program will exit with status 0. If there is an
 * argument the program will exit with a status equal to the first argument.
 * Return: Always 0;
 */
int exit_shell(char **args, char **env)
{
	int status;

	(void) env;
	if (args[1] == NULL)
		exit(0);
	status = _atoi(args[1]);
	exit(status);
}
