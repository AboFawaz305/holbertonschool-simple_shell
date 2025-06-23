#include <stdio.h>
#include "simple_shell.h"

/**
 * get_cmd - get a command from stdin
 * @buffer: a pointer to the buffer to store the command
 * @size: a pointer to the size of the command
 *
 * Return: -1 if C-d or size of the command or 0 if the user didnt input a
 * command
 */
int get_cmd(char **buffer, size_t *size)
{
	int bytes;
	char *cmd;

	bytes = getline(buffer, size, stdin);
	cmd = *buffer;
	if (cmd == NULL)
		return (0);
	if (cmd[0] == 4 || bytes == -1)
	{
		/* We catched a C-d */
		clearerr(stdin); /* clear stdin so we can use getline again */
		return (-1);
	}
	if (cmd[0] == 10)
		/* We catched an empty command */
		return (0);
	if (cmd[bytes - 1] == '\n')
	{
		/* remove the '\n' at the end if any */
		cmd[bytes - 1] = '\0';
		bytes--;
	}
	return (bytes);
}
