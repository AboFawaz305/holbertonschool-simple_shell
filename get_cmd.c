#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "simple_shell.h"

/**
 * count_words - returns the number of words in s
 * @s: a string
 *
 * Return: the number of words in s
 */
int count_words(char *s)
{
	if (*s == '\0')
		return (0);
	if (*s != ' ' && (*(s + 1) == ' ' || *(s + 1) == '\0'))
		return (1 + count_words(s + 1));
	return (count_words(s + 1));
}

/**
 * free_args - free an arguments array allocated with paese_cmd
 * @args: an arguments array allocated with parse_cmd
 */
void free_args(char **args)
{
	int i = 0;

	while (args[i] != NULL)
		free(args[i++]);
	free(args);
}

/**
 * parse_cmd - parse a command into its name and arguments
 * @cmd: a pointer to the place where you store the command name
 * @args: a pointer to the place to store the command arguments
 * @input: the input string
 *
 * Description: cmd and args should be a reference to two NULL pointers. you
 * should free cmd and free args with free_args() after you finish using them.
 * Return: 1 on success or -1 on malloc error or -2 if there is no command.
 */
int parse_cmd(char **cmd, char ***args, char *input)
{
	char *word;
	char *input_copy;
	int i;

	*args = malloc(sizeof(char *) * (count_words(input) + 1));
	input_copy = strdup(input);
	if (*args == NULL || input_copy == NULL)
	{
		free(*args);
		free(input_copy);
		return (-1);
	}
	word = strtok(input_copy, " ");
	if (word == NULL)
	{
		free(*args);
		free(input_copy);
		return (-2);
	}
	if (word[0] == '#')
	{
		free(*args);
		free(input_copy);
		return (-3);
	}
	*cmd = strdup(word);
	i = 0;
	while (word != NULL)
	{
		(*args)[i] = strdup(word);
		i++;
		word = strtok(NULL, " ");
	}
	(*args)[i] = NULL;
	free(input_copy);
	return (1);
}

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
