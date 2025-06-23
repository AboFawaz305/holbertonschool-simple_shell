#ifndef _SIMPLE_SHELL_H
#define _SIMPLE_SHELL_H

#include <stddef.h>

#define CMD_BUFFER_SIZE 2048

int execute(char *cmd, char **env, char **argv);
int get_cmd(char *buffer, int size);

#endif
