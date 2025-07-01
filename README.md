# Simple Shell

A simple implementation of a shell for Linux systems.

## Description

This project is a simple UNIX command line interpreter that replicates functionalities of the simple shell (sh). The shell can run in both interactive and non-interactive mode.

## Features

- Display a prompt and wait for the user to type a command
- Execute simple commands with arguments
- Handle the PATH environment variable
- Implement built-in commands:
  - `exit` - exit the shell
  - `env` - print environment variables
- Handle command not found errors
- Support for executable files in PATH

## Compilation

To compile the shell, use:

```bash
gcc -Wall -Wextra -Werror -pedantic -std=gnu89 *.c -o hsh
```

## Usage

### Interactive Mode

Run the shell in interactive mode:

```bash
./hsh
```

Example:
```bash
$ ./hsh
#cisfun$ ls
builtin.c  execute.c  get_cmd.c  hsh  interactive.c  main.c  README.md  simple_shell.h  utilities.c
#cisfun$ pwd
/home/user/simple_shell
#cisfun$ exit
$
```

### Non-Interactive Mode

The shell can also handle commands passed through pipes:

```bash
$ echo "ls" | ./hsh
builtin.c  execute.c  get_cmd.c  hsh  interactive.c  main.c  README.md  simple_shell.h  utilities.c
$
```

## Built-in Commands

- `exit [status]` - Exit the shell with optional exit status
- `env` - Print the current environment variables

## Files

- `main.c` - Entry point of the program
- `interactive.c` - Handles interactive mode
- `execute.c` - Command execution and PATH handling
- `builtin.c` - Built-in command implementations
- `get_cmd.c` - Command parsing and input handling
- `utilities.c` - Utility functions
- `simple_shell.h` - Header file with function prototypes and structures

## Authors

See the AUTHORS file for a list of contributors to this project.
