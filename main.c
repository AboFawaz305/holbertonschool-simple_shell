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
	/* TODO: ADD non_interactive mode support(piped input). */
	interactive_mode(env);
	return (0);
}
