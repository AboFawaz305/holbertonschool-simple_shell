#ifndef _SIMPLE_SHELL_H
#define _SIMPLE_SHELL_H

#include <stddef.h>

int execute(char *cmd, char **env, char **argv);
int get_cmd(char **buffer, size_t *size);
char *get_env(char *name, char **env);
int is_in_path(char *cmd, char **env);
int parse_cmd(char **cmd, char ***args, char *input);
void free_args(char **args);

#endif
