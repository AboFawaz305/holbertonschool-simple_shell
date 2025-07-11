#include "simple_shell.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * builtin_commands - array of builtin commands
 */
static struct builtin_cmd builtin_commands[] = {
	/* {"exit", exit_shell}, */
	{"env", print_env},
	{NULL, NULL}
};

/**
 * is_builtin - returns with cmd is a builtin command or not
 * @cmd: a command name
 *
 * Return: 1 if cmd is a builtin or 0 otherwise
 */
int is_builtin(char *cmd)
{
	int i;

	if (cmd == NULL)
		return (0);

	for (i = 0; builtin_commands[i].name != NULL; i++)
	{
		if (strcmp(cmd, builtin_commands[i].name) == 0)
			return (1);
	}

	return (0);
}

/**
 * _atoi - convert s to an integer
 * @s: a null terminated string.
 * @prog_name: the program_name
 *
 * Return: s converted to an int.
 */
int _atoi(char *s, char *prog_name)
{
	int r = 0;
	int size = strlen(s) - 1;
	int b = 1, x = 0;

	if (s[0] == '-')
	{
		b *= -1;
		x += 1;
	}
	while (size >= x)
	{
		if (s[size] < '0' || s[size] > '9')
		{
			fprintf(stderr, "%s: exit: numeric argument required\n", prog_name);
			return (2);
		}
		r += (s[size] - '0') * b;
		b *= 10;
		size--;
	}

	return (r);
}

/**
 * print_env - print the environment variables
 * @args: the arguments array
 * @env: the envrironment variables array
 *
 * Return: Always 0
 */
int print_env(char **args, char **env)
{
	(void) args;
	while (*env != NULL)
	{
		printf("%s\n", *env);
		env++;
	}
	return (0);
}

/**
 * run_builtin - run a given builtin command
 * @cmd: the builtin command name
 * @args: command arguments array
 * @env: environment variables array
 *
 * Return: command function return value on success, -1 to -10 on error
 */
int run_builtin(char *cmd, char **args, char **env)
{
	int i;

	if (cmd == NULL)
		return (-1);

	for (i = 0; builtin_commands[i].name != NULL; i++)
	{
		if (strcmp(cmd, builtin_commands[i].name) == 0)
		{
			return (builtin_commands[i].func(args, env));
		}
	}

	/* Should not reach here according to problem statement */
	/* but returning error code just in case */
	return (-2);
}
