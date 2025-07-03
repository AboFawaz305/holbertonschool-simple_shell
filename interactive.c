#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "simple_shell.h"

/**
 * run_command - run a command line
 * @line: a null terminated string
 * @exit_status: last command exit status
 * @env: the environment variables array
 * @line_num: the current line number
 * @prog_name: the program name
 *
 * Return: the command exit status
 */
int run_command(char *line, char **env, int exit_status,
		int line_num, char *prog_name)
{
	char *cmd = NULL, **args = NULL;
	int status = 0, result;

	result = parse_cmd(&cmd, &args, line);
	if (result == -1)
	{
		fprintf(stderr, "Memory allocation error\n");
		return (0);
	}
	if (result == -2 || result == -3)
		return (0);
	if (is_builtin(cmd))
		status = run_builtin(cmd, args, env);
	else if (strcmp(cmd, "exit") == 0)
	{
		free(line);
		free(cmd);
		if (args[1] != NULL)
			exit_status = _atoi(args[1]);
		free_args(args);
		exit(exit_status);
	}
	else
		status = execute(cmd, env, args, line_num, prog_name);
	free(cmd);
	free_args(args);
	return (status);
}

/**
 * interactive_mode - start the program in interactive mode
 * @env: environment variables
 * @status: a pointer to the palce to store the status
 * @prompt: the prompt text
 *
 * Description: This function starts the program in interactive mode.
 * It prints a prompt to the user and waits until they write a command.
 * After the user hits enter, the program executes the command.
 * After command execution, it prints the prompt again and waits for
 * another command. When the user hits Ctrl-D, the program stops.
 */
void interactive_mode(char **env, int *status, char *prompt)
{
	char *buffer = NULL;
	size_t n = 0;
	int cmd_size;

	while (1)
	{
		printf("%s", prompt);
		fflush(stdout);
		cmd_size = get_cmd(&buffer, &n);
		if (cmd_size == 0)
			continue;
		if (cmd_size == -1)
			break;
		*status = run_command(buffer, env, *status, 0, NULL);
	}
	free(buffer);
}
