# SHELL 

## AUTHORS
**Angela Vergara** 

  <p align="center">
      <img align="center" src="https://avatars.githubusercontent.com/u/85180677?v=4" alt="Angela Vergara" height="80" width="80" />
        <a href="https://github.com/anversa-pro" target="blank"><img align="center" src="https://raw.githubusercontent.com/devicons/devicon/9f4f5cdb393299a81125eb5127929ea7bfe42889/icons/github/github-original.svg" alt="Github Angela" height="30" width="40" /></a> 
 </p>  <br>
 
 **Maria Paula Medina**
 
   <p align="center">
	    <img align="center" src="https://avatars.githubusercontent.com/u/70358968?v=4" alt="Maria Paula Medina" height="80" width="80" />
	      <a href="https://github.com/Mapu456" target="blank"><img align="center" src="https://raw.githubusercontent.com/devicons/devicon/9f4f5cdb393299a81125eb5127929ea7bfe42889/icons/github/github-original.svg" alt="Github Maria Paula" height="30" width="40" /></a>
  </p>
    <br>

### SHELL Definition

Shell is a command-line interpreter that provides a command line user interface commonly for Unix-like operating systems. The shell is both an interactive command language and a scripting language, and is used by the operating system to control the execution of the system using shell scripts.

Users typically interact with a shell using a terminal emulator; however, direct operation via serial hardware connections or Secure Shell are common for server systems. All Unix shells provide filename wildcarding, piping, here documents, command substitution, variables and control structures for condition-testing and iteration.

The purpouse of this prroject is to Write a simple UNIX command interpreter.

### About this Repo

**Requirements to built it:**  
	* All your files will be compiled on Ubuntu 20.04 LTS.    
	* All your files should end with a new line.  
	* A README.md file, at the root of the folder of the project is mandatory.  
	* Your shell should not have any memory leaks  
	* No more than 5 functions per file  
	* All your header files should be include guarded  

**C Files:**
* _printf.c:
* _printf2.c:
* errorAccess_f.c:
* function_strings.c:
* functions_01.c:
* functions_02.c:
* shell.c:
* shell_builtins.c:

**Header:**
shell.h:

**Man Page:**
To access the man page __man_1_simple_shell__ directly in a terminal, download the file and move it to the directory /usr/share/man/man1 where the system stores man pages for User shell commands.
You can view it by typing the following command: `cd /usr/share/man/man1` otherwise into the project directory by typing `man ./man_1_simple_shell`

### How to use this project
1. Please clone this repo into your sandbox or local terminal.
2. Access to the directory and compile all C files with the command: gcc -Wall -Wextra -Werror -pedantic -std=gnu89 *.c - o hsh ( hsh is a suggested name, not mandatory)
3. In case you prefer to use the non-interactive mode with the Teletypewriter: write down your instruction and pipeline the executable you create on the previous step.  
	* ieg. Display the list of files on current directory order and long detailed. `echo /usr/bin/ls -la | ./hsh`  
	<a href=#><https://github.com/anversa-pro/IMG/blob/491e1f93129e823a4d5ebb5e6353c1e1c9bb4ff8/Examples%20of%20use%20-%20nonInteractive.png"/></a>
4. By  typing `./hsh` runs the program for you to execute the instructions on this mini-shell.  
	* ieg. to show files on current directory, insert `ls` instruction, then to show the path of you current directry, insert `pwd` instruction.    
	<a href=#><https://github.com/anversa-pro/IMG/blob/491e1f93129e823a4d5ebb5e6353c1e1c9bb4ff8/Examples%20of%20use.png"/></a>
5. To finish the execution and exit the program just insert `exit` or press `CRTL + D` on your keyboard.
	
### Flowchart  
This image shows the general procces designed to perform an emulation of the shell.  
<a href=#><https://github.com/anversa-pro/IMG/blob/5c2e5e5c4e2578dbcf38a8d76beecd293b8d187d/Diagram-hsh_flowchart_v2.0.png" /></a>
