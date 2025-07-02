#include <stdlib.h>
#include <stdio.h>
#include "simple_shell.h"

/**
 * main - a simple shell program
 * @argc: the size of argv
 * @argv: the arguments vector
 * @env: the environment variables
 *
 * Return: 0 on success or non-zero on failure
 */
int main(int argc, char **argv, char **env)
{
	(void) argc;
	(void) argv;
	if (is_non_interactive_mode())
	{
		char *buffer = NULL, *cmd = NULL, **args = NULL;
		size_t n = 0;
		int cmd_size, result;

		while ((cmd_size = get_cmd(&buffer, &n)) != -1)
		{
			if (cmd_size == 0)
				continue;
			result = parse_cmd(&cmd, &args, buffer);
			if (result == -1)
			{
				fprintf(stderr, "Memory allocation error\n");
				continue;
			}
			if (result == -2 || result == -3)
				continue;
			if (is_builtin(cmd))
				run_builtin(cmd, args, env);
			else
				execute(cmd, env, args);
			free(cmd);
			free_args(args);
			cmd = NULL;
			args = NULL;
		}
		free(buffer);
		return (0);
	}
	interactive_mode(env);
	return (0);
}
