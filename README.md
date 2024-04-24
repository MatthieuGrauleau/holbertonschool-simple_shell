![HEADER](https://github.com/MatthieuGrauleau/holbertonschool-simple_shell/blob/david/img/header.png)

# :computer: SIMPLE SHELL / Holberton School :fr:

## :memo: DESCRIPTION & ENVIRONEMENT :

This project is initiated by Holberton School France for creating a simple shell writen in C.

- Used on Linux environment and developed under ubuntu 22.04 LTS.

This project consisting of creating a basic shell for all terminal in colaboration with peers of students of Holberton School.

## :abacus: Compilation :
To compile your code, you should use the following command:

```gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh```

## :game_die: Requirements :
> - Allowed editors: vi, vim, emacs
> - All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89
> - All your files should end with a new line
> - A README.md file, at the root of the folder of the project is mandatory
> - Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
> - Your shell should not have any memory leaks
> - No more than 5 functions per file
> - All your header files should be include guarded
> - Use system calls only when you need to (why?)

## :inbox_tray: Mandatory Task :

> 0. README, man, AUTHORS
- Write a README
- Write a man for your shell.
- You should have an AUTHORS file at the root of your repository, listing all individuals having contributed content to the repository. Format, see Docker.

> 1. Betty would be proud
- Write a beautiful code that passes the Betty checks.

> 2. Simple shell 0.1
- Write a UNIX command line interpreter.  
- Display a prompt and wait for the user to type a command. A command line always ends with a new line.
- The prompt is displayed again each time a command has been executed.
- The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.
- The command lines are made only of one word. No arguments will be passed to programs.
- If an executable cannot be found, print an error message and display the prompt again.
- Handle errors.
- You have to handle the “end of file” condition (Ctrl+D)
You don’t have to:
- use the PATH
- implement built-ins
- handle special characters : ", ', `, \, *, &, #
- be able to move the cursor
- handle commands with arguments

> 3. Simple shell 0.2
- Handle command lines with argument

> 4. Simple shell 0.3
- Handle the PATH
- fork must not be called if the command doesn’t exist

> 5. Simple shell 0.4
- Implement the exit built-in, that exits the shell
- Usage: exit
- You don’t have to handle any argument to the built-in exit

> 6. Simple shell 1
- Implement the env built-in, that prints the current environment

# :mag: BASIC USAGE & EXEMPLE :

You can only used this commands in the simple shell and you find here command POSIX:
- [LIST COMMAND POSIX](https://en.wikipedia.org/wiki/List_of_POSIX_commands)

|  Command  | Definition                                             |
|----------:|--------------------------------------------------------|
|    ls     | List the files in the current directory.               |
|    cp     | copy a file or Directory(ex ```cp test```).            |
|    mv     | Move a file and or rename (ex ```mv file1 file2```).   |
|    rm     | Delete a file or repertory (ex ```rm -R \Folder```)    |
|    pwd    | Print working directory                                |
|    env    | Print the environment system and give informations     |
|    exit   | Exit in the Shell or with Ctrl + C                     |

## :newspaper: Exemple in the shell : 
![Exemple_shell](https://github.com/MatthieuGrauleau/holbertonschool-simple_shell/blob/david/img/screenshot_shell.png)

### commands in shell :

- ls (RESULTED)
```
$ ./hsh
$ ls
AUTHORS    _ctrl_d.c  _exit.c    built_in_function.c  hsh  main.c  man_1_simple_shell  prompt.c    str_tok.c
README.md  _env.c     _strlen.c  get_line.c           img  main.h  process.c           readline.c
```

- env (RESULTED)
```
$./hsh
$ env
SHELL=/bin/bash
PWD=/root/holbertonschool-simple_shell
LOGNAME=root
MOTD_SHOWN=pam
HOME=/root
LESSCLOSE=/usr/bin/lesspipe %s %s
TERM=xterm
LESSOPEN=| /usr/bin/lesspipe %s
USER=root
SHLVL=1
SSH_CLIENT=10.43.223.216 36764 22
DEBUGINFOD_URLS=
PATH=/usr/local/sbin
SSH_TTY=/dev/pts/0
_=./hsh
OLDPWD=/root
```
ETC...

# :bar_chart: FLOWCHART :
![FLOWCHART](https://github.com/MatthieuGrauleau/holbertonschool-simple_shell/blob/david/img/flowchart_simpleshell.png)

# :floppy_disk: CONTRIBUTING & AUTHOR :

It's project for Holberton School France at Bordeaux.
Thanks for the contribution and help for this project.

- [[@MatthieuGrauleau](https://github.com/MatthieuGrauleau)]
- [[@ghinzuka](https://github.com/ghinzuka)]
- [[@Goliath33](https://github.com/Goliath33)]

# COPYRIGHT : 

MIT License

Copyright (c) [2024]    

- [[@MatthieuGrauleau](https://github.com/MatthieuGrauleau)]
- [[@ghinzuka](https://github.com/ghinzuka)]
- [[@Goliath33](https://github.com/Goliath33)]

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
