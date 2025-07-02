# Simple Shell

A simple UNIX command line interpreter written in C that replicates some of the functionality of the `/bin/sh` shell.

## Description

This project is a simple shell implementation that can execute commands in both interactive and non-interactive modes. It includes support for built-in commands, external program execution via PATH resolution, and proper process management using fork and exec system calls.

## Features

- **Interactive Mode**: Displays a prompt (`#cisfun$ `) and waits for user input
- **Non-Interactive Mode**: Executes commands from pipes or redirected input
- **Built-in Commands**: 
  - `exit [status]` - Exit the shell with optional status code
  - `env` - Display environment variables
- **External Commands**: Execute programs found in PATH directories
- **Error Handling**: Proper error messages for command not found and execution failures
- **Memory Management**: Clean allocation and deallocation of dynamic memory
- **Signal Handling**: Graceful handling of Ctrl+D (EOF)

## Requirements

- **OS**: Linux/Unix-like systems
- **Compiler**: GCC
- **Standards**: C89/C90 compliant
- **Coding Style**: Betty style guide
- **Memory**: No memory leaks (valgrind clean)

## Compilation

Compile the shell using GCC with the following flags:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

## Usage

### Interactive Mode

Run the shell without any arguments:

```bash
./hsh
```

Example session:
```bash
$ ./hsh
#cisfun$ ls -la
total 120
drwxrwxr-x 3 user user  4096 Dec 7 10:30 .
drwxrwxr-x 5 user user  4096 Dec 7 10:29 ..
-rwxrwxr-x 1 user user 18816 Dec 7 10:30 hsh
-rw-rw-r-- 1 user user  1234 Dec 7 10:28 main.c
#cisfun$ pwd
/home/user/simple_shell
#cisfun$ env
PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin
HOME=/home/user
USER=user
...
#cisfun$ exit
$
```

### Non-Interactive Mode

Use the shell with pipes or input redirection:

```bash
echo "ls -la" | ./hsh
```

or

```bash
./hsh < script.txt
```

## File Structure

| File | Description |
|------|-------------|
| `main.c` | Entry point and mode detection |
| `interactive.c` | Interactive mode implementation |
| `execute.c` | Command execution and PATH resolution |
| `builtin.c` | Built-in commands implementation |
| `get_cmd.c` | Command parsing and input processing |
| `utilities.c` | Utility functions |
| `simple_shell.h` | Header file with function prototypes |

## Built-in Commands

### exit [status]
Exits the shell with an optional exit status.
- `exit` - Exit with status 0
- `exit 98` - Exit with status 98

### env
Prints all environment variables to standard output.

## Implementation Details

### Command Execution Flow
1. Read input from stdin using `getline()`
2. Parse command and arguments using `strtok()`
3. Check if command is built-in
4. If built-in, execute directly
5. If external, search in PATH directories
6. Fork child process and execute with `execve()`
7. Parent waits for child completion

### Memory Management
- Dynamic allocation for command parsing
- Proper cleanup of allocated memory
- No memory leaks verified with valgrind

### Error Handling
- Command not found returns exit status 127
- Fork failures handled with appropriate error messages
- Invalid arguments handled gracefully

## Testing

The project includes automated testing via GitHub Actions:
- Betty style checker for code formatting
- Betty documentation checker for function documentation

Run local tests:
```bash
# Style check
betty-style *.c *.h

# Documentation check  
betty-doc *.c *.h
```

## Limitations

- Does not support:
  - Command chaining (`;`, `&&`, `||`)
  - Input/output redirection (`>`, `<`, `>>`)
  - Pipes (`|`)
  - Variable expansion (`$VAR`)
  - Globbing (`*`, `?`)
  - Job control
  - Command history
  - Tab completion

## Exit Status

- `0`: Successful execution
- `127`: Command not found
- Other: Status returned by executed command or specified in `exit`

## Authors

See [AUTHORS](AUTHORS) file for contributor information.

## License

This project is part of a learning exercise and follows educational use guidelines.
