#ifndef _SIMPLE_SHELL_H
#define _SIMPLE_SHELL_H

#include <stddef.h>

/**
 * struct builtin_cmd - structure for builtin commands
 * @name: the command name
 * @func: function pointer to the builtin function
 */
struct builtin_cmd
{
	char *name;
	int (*func)(char **args, char **env);
};

int _atoi(char *s, char *prog_name);
int run_command(char *line, char **env, int exit_status,
		int line_num, char *prog_name);
int execute(char *cmd, char **env, char **argv, int line_num, char *prog_name);
int get_cmd(char **buffer, size_t *size);
char *get_env(char *name, char **env);
int is_in_path(char *cmd, char **env);
char *get_full_path(char *cmd, char **env);
int parse_cmd(char **cmd, char ***args, char *input);
void free_args(char **args);
int exit_shell(char **args, char **env);
int print_env(char **args, char **env);
int is_builtin(char *cmd);
int run_builtin(char *cmd, char **args, char **env);
void interactive_mode(char **env, int *status, char *prompt);
int is_non_interactive_mode(void);

#endif
