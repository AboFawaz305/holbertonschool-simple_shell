#ifndef _SIMPLE_SHELL_H
#define _SIMPLE_SHELL_H

#include <stddef.h>

int execute(char *cmd, char **env, char **argv);
int get_cmd(char **buffer, size_t *size);
char *get_env(char *name, char **env);
int is_in_path(char *cmd, char **env);
char *get_full_path(char *cmd, char **env);

#endif
