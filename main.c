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
	char *buffer = NULL;
	size_t n = 0;
	char *cmd_argv[] = {NULL};
	int cmd_size, is_nim;

	(void) argc;
	(void) argv;
	is_nim = is_non_interactive_mode();
	while (1)
	{
		if (!is_nim)
			printf("#cisfun$ ");
		cmd_size = get_cmd(&buffer, &n);
		if (cmd_size == 0)
			continue;
		if (cmd_size == -1)
			break;
		execute(buffer, env, cmd_argv);
		if (is_nim)
			break;
	}
	free(buffer);
	return (0);
}
