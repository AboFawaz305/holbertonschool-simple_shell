#include <stdlib.h>
#include <stdio.h>
#include "simple_shell.h"
#include <signal.h>
#include <unistd.h>

/**
 * ctrl_c_handler - a handler for control C events
 * @sig: the received signal number
 */
void ctrl_c_handler(int sig)
{
	(void) sig;
	write(STDIN_FILENO, "\n", 1);
	printf("#cisfun$ ");
	fflush(stdout);
}

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
	int status = 0;
	char *prompt = "#cisfun$ ";
	(void) argc;
	(void) argv;
	signal(SIGINT, ctrl_c_handler);
	if (is_non_interactive_mode())
	{
		char *buffer = NULL;
		size_t n = 0;
		int cmd_size, line_num = 0;

		while ((cmd_size = get_cmd(&buffer, &n)) != -1)
		{
			line_num++;
			if (cmd_size == 0)
				continue;
			status = run_command(buffer, env, status, line_num, argv[0]);
		}
		free(buffer);
		return (status);
	}
	interactive_mode(env, &status, prompt);
	return (status);
}
