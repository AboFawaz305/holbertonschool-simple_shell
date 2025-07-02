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
	if (is_non_interactive_mode())
	{
		char *buffer = NULL, *cmd = NULL, **args = NULL;
		size_t n = 0;
		int cmd_size, result, exit_status = 0;
		int line_num = 0;

		while ((cmd_size = get_cmd(&buffer, &n)) != -1)
		{
			line_num++;
			if (cmd_size == 0)
				continue;
			result = parse_cmd(&cmd, &args, buffer);
			if (result == -1)
			{
				fprintf(stderr, "Memory allocation error\n");
				exit_status = 1;
				break;
			}
			if (result == -2 || result == -3)
				continue;
			if (is_builtin(cmd))
			{
				exit_status = run_builtin(cmd, args, env);
				/* builtin commands like exit will terminate the program */
			}
			else
			{
				exit_status = execute(cmd, env, args, line_num, argv[0]);
			}
			free(cmd);
			free_args(args);
			cmd = NULL;
			args = NULL;
			
			/* In non-interactive mode, exit with command status if it fails */
			if (exit_status != 0)
			{
				free(buffer);
				exit(exit_status);
			}
		}
		free(buffer);
		exit(exit_status);
	}
	interactive_mode(env);
	return (0);
}
