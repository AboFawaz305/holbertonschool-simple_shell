#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "simple_shell.h"

/**
 * interactive_mode - start the program in interactive mode
 * @env: environment variables
 *
 * Description: This function starts the program in interactive mode.
 * It prints a prompt to the user and waits until they write a command.
 * After the user hits enter, the program executes the command.
 * After command execution, it prints the prompt again and waits for
 * another command. When the user hits Ctrl-D, the program stops.
 */
void interactive_mode(char **env)
{
	char *buffer = NULL, *cmd = NULL, **args = NULL;
	size_t n = 0;
	int cmd_size, result;

	while (1)
	{
		printf("#cisfun$ ");
		fflush(stdout);

		cmd_size = get_cmd(&buffer, &n);
		if (cmd_size == 0)
			continue;
		if (cmd_size == -1)
			break;

		result = parse_cmd(&cmd, &args, buffer);
		if (result == -1)
		{
			fprintf(stderr, "Memory allocation error\n");
			continue;
		}
		if (result == -2)
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
}