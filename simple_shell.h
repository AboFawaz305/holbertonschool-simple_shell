#ifndef _SIMPLE_SHELL_H
#define _SIMPLE_SHELL_H

#include <stddef.h>

int execute(char *cmd, char **env, char **argv);
int get_cmd(char **buffer, size_t *size);

#endif
