# Simple Shell

This project is a simple UNIX command-line shell implemented in C. It provides basic functionalities for interpreting and executing user commands, similar to standard shells like `sh` or `bash`.

## Description

The simple shell reads user input from standard input in interactive mode, parses commands, and executes them in a loop until the user exits. It supports executing system programs and handling arguments. The shell is designed for educational purposes and demonstrates fundamental concepts of process management and command execution in UNIX systems.

## Compilation

To compile the shell, use the following command:

```sh
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
```

This will create an executable named `hsh`.

## Usage Examples

After compiling, you can run the shell interactively:

```sh
./hsh
```

You can then enter commands like:

```sh
$ ls -l
$ /bin/echo Hello, World!
$ pwd
$ exit
```

## Testing

You can test the shell by running it and entering various UNIX commands in interactive mode. Try commands such as `ls`, `pwd`, `echo`, or any executable available on your system.

## Authors

See the [AUTHORS](AUTHORS) file for a list of contributors to this project.
