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
	char buffer[CMD_BUFFER_SIZE];
	char *cmd_argv[] = {NULL};
	int cmd_size;

	(void) argc;
	(void) argv;
	while (1)
	{
		printf("#cisfun$ ");
		cmd_size = get_cmd(buffer, CMD_BUFFER_SIZE);
		if (cmd_size == 0)
			continue;
		if (cmd_size == -1)
			break;

		execute(buffer, env, cmd_argv);
	}

	return (0);
}
