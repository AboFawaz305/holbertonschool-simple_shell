#include <stdlib.h>
#include <stdio.h>
#include "simple_shell.h"
#include <string.h>

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
		char *buffer = NULL;
		size_t n = 0;
		int cmd_size, status = 0;

		while ((cmd_size = get_cmd(&buffer, &n)) != -1)
		{
			if (cmd_size == 0)
				continue;
			status = run_command(buffer, env, status);
		}
		free(buffer);
		return (0);
	}
	interactive_mode(env);
	return (0);
}
