# Simple Shell

A minimalist UNIX command line interpreter written in C that replicates basic functionality of the simple shell (sh).

## Description

This project implements a simple UNIX command line interpreter that can run in both interactive and non-interactive modes. The shell executes commands, handles the PATH environment variable, and supports built-in commands.

## Requirements

- GCC compiler
- Linux/Unix operating system
- Standard C library
- POSIX-compliant system

## Installation

1. Clone the repository:
```bash
git clone <repository-url>
cd simple_shell
```

2. Compile the shell:
```bash
gcc -Wall -Wextra -Werror -pedantic -std=gnu89 *.c -o hsh
```

3. Run the shell:
```bash
./hsh
```

## Usage

**Interactive mode:**
```bash
./hsh
#cisfun$ ls
#cisfun$ pwd
#cisfun$ exit
```

**Non-interactive mode:**
```bash
echo "ls" | ./hsh
```

## Testing

### Basic Command Testing
```bash
# Test basic commands
echo "ls" | ./hsh
echo "pwd" | ./hsh
echo "/bin/ls" | ./hsh

# Test built-in commands
echo "env" | ./hsh
echo "exit" | ./hsh
echo "exit 98" | ./hsh

# Test error handling
echo "nonexistent_command" | ./hsh
```

### Interactive Testing
```bash
./hsh
#cisfun$ ls -la
#cisfun$ pwd
#cisfun$ env
#cisfun$ exit 0
```

### Advanced Testing
```bash
# Test with PATH
echo "ls" | ./hsh
# Test with absolute path
echo "/bin/ls" | ./hsh
# Test comments
echo "# This is a comment" | ./hsh
# Test empty lines
echo "" | ./hsh
```



## Structure and Algorithm

### Program Flow
1. **Mode Detection**: Determine if running in interactive or non-interactive mode using `isatty()`
2. **Input Processing**: Get command input from user or stdin using `getline()`
3. **Command Parsing**: Parse input into command and arguments using `strtok()`
4. **Command Classification**: Check if command is built-in or external
5. **Execution**: Execute built-in or external command using `fork()` and `execve()`
6. **Cleanup**: Free allocated memory and repeat

### Key Algorithms

**Command Parsing Algorithm:**
```c
int parse_cmd(char **cmd, char ***args, char *input)
{
    // Count words in input
    // Allocate memory for arguments array
    // Tokenize input string using strtok()
    // Store each token as separate argument
    // Return success/error status
}
```

**PATH Search Algorithm:**
```c
int is_in_path(char *cmd, char **env)
{
    // Get PATH environment variable
    // Split PATH by ':' delimiter
    // For each directory in PATH:
    //   Construct full path: directory + "/" + command
    //   Check if file exists and is executable using access()
    // Return 1 if found, 0 if not found
}
```

## Array of Struct with Pointers to Function

### Built-in Commands Implementation
```c
struct builtin_cmd
{
    char *name;                           // Command name string
    int (*func)(char **args, char **env); // Function pointer
};

static struct builtin_cmd builtin_commands[] = {
    {"exit", exit_shell},    // Maps "exit" to exit_shell function
    {"env", print_env},      // Maps "env" to print_env function
    {NULL, NULL}             // Sentinel value to mark end of array
};
```

### Function Pointer Usage
```c
int run_builtin(char *cmd, char **args, char **env)
{
    for (i = 0; builtin_commands[i].name != NULL; i++)
    {
        if (strcmp(cmd, builtin_commands[i].name) == 0)
        {
            return (builtin_commands[i].func(args, env)); // Call through pointer
        }
    }
}
```

**Benefits**: Modularity, easy to add new commands, efficient O(n) lookup, clean separation of logic.

## Basic %s Function Usage

### String Formatting Implementation

**Path Construction:**
```c
sprintf(full_path, "%s/%s", dir, cmd);  // Combines directory and command
```

**Output Display:**
```c
printf("%s\n", *env);  // Prints environment variables
```

**Error Messages:**
```c
fprintf(stderr, "%s: command not found\n", cmd);  // Error to stderr
```

The `%s` format specifier safely formats string arguments, preventing format string vulnerabilities while enabling dynamic message construction.

## Main Program Flow and Packages Used

### System Libraries Used
- **stdio.h**: `printf()`, `fprintf()`, `getline()`, `perror()`
- **stdlib.h**: `malloc()`, `free()`, `exit()`, `strdup()`
- **string.h**: `strcmp()`, `strlen()`, `strtok()`, `strchr()`
- **unistd.h**: `fork()`, `execve()`, `access()`, `isatty()`
- **sys/wait.h**: `wait()`, `WIFEXITED()`, `WEXITSTATUS()`

### Program Architecture
```
main.c → interactive.c → get_cmd.c → builtin.c/execute.c → utilities.c
```

**Flow**: Mode detection → Input loop → Command parsing → Built-in check → Execution → Cleanup

## Distribution of Work

### AboFawaz305 Responsibilities
- **Core Infrastructure**: `main.c`, `interactive.c`, `get_cmd.c`
- **Input Processing**: Command reading and parsing algorithms
- **Interactive Interface**: Prompt display and user interaction
- **Memory Management**: Dynamic allocation for command parsing
- **Architecture Design**: Overall program structure and flow

### Abdulrahman9907 Responsibilities
- **Execution Engine**: `execute.c`, `builtin.c`, `utilities.c`
- **Process Management**: Fork/exec implementation
- **PATH Resolution**: Environment variable processing
- **Built-in Commands**: Implementation of shell built-ins
- **System Integration**: UNIX system call integration

### Shared Work
- Header file design (`simple_shell.h`)
- Testing and debugging
- Code review and integration
- Documentation and optimization

## Authors

See [AUTHORS](AUTHORS) file for contributors.
