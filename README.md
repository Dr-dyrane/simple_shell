# SIMPLE SHELL

A simple UNIX command interpreter written in C.

## Table of Contents

- [Introduction](#introduction)
- To Get Started
- How to use
- [Common commands to enter]
- [Built-in Commands](#built-in-commands)
- [Authors]
- [Flowchart](#flowchart)

# Introduction

Simple Shell is a UNIX command interpreter that reads IN commands from either a standard inpur or from a file, and execute them.

This program was written as part of a coding challenge on Ubuntu 20.04 LTS for ALX SE cohort 12 group project: simple\_shell, and may not be suitable for use in any production enviroments.

## To Get Started

## How to Install

build the program by simply runing the following commands:

It will build the `shell` executable.

To start , clone the repository and compile the program with `gcc` compiler:

##bash
$ git clone https://github.com/Dr-dyrane/simple_shell.git
$ cd simple_shell
$ gcc -Wall -Werror -Wextra -pedantric *.c -o shell

## Description

This program implements a basic shell in C language. It provides a simple command-line interface for the user to execute commands. The program reads input from the user and executes the command using the `execve` system call.

## How to use

Run the `shell` executable. The program will display a prompt and wait for user's input. Then enter a command and press enter in ordder to execute the command.

Bash
$ ./shell

A prompt will appear for you

Like this
(sh)$
```
Now you can enter commands to execute, each command at a time, or multiple commands on the same line seperated by a semicolon;

Common commands to enter
(sh)$ ls
Doc.txt doc2.txt doc3.txt doc4.txt
(sh)$ pwd; ls
/home/user/simple_shell
Doc.txt doc2.txt doc3.txt doc4.txt
```

If you want to exit the shell, just type the `exit` command:

Like this
(sh)$ exit
```

## Common Commands

The Simple Shell supports a variety of commands, including built-in commands and external commands:

Like this
$ <command> [arguments]
```

## Common Examples


$ ls
$ cd /home/user/my_directory
$ echo "Hello, world!"
```

## Built-in Commands

This Shell also includes some built-in commands:

```txt
cd - To Change the current working directory.
exit - To Exit the shell.
```

## Examples

Like this
$ cd /home/user/directory
$ exit
```

## Exit Status

This Shell program returns an exit status to indicate whether the command was executed successfully or not. And If the command was executed properly, your exit status will be 0. Also if the command was never executed properly, your exit status will be a zero integer.

## Authors

This progam was written by;

Ukpon Umoren [<ukpono9@gmail.com>](https://github.com/ukeremi) and
Alexander Udeogaranya [<halodyrane@gmail.com>](https://github.com/Dr-dyrane).

## Aknowledgement

This program is done under the [ALX SE Program](https://www.alxafrica.com/software-engineering/)

## Flowchart

![simple shell](https://user-images.githubusercontent.com/115133529/234009678-90eae536-26f3-4ee5-b0ba-4f1eb5fe1549.png)

