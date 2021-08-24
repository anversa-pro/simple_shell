#ifndef H_SHELL
#define H_SHELL

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/resource.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>
#define PROMPT "$ "
#define DELIM " "
#define DELIM2 ":"
#define SLASH "/"

/*		MAIN		*/

/* global variable that extract env of system*/
extern char **environ;
/**
* struct inputdata - shell structure to save and manage info and args
* *@inputarray: pointer to a copy of terminal input string
* @inputsize: size of terminal input string
* *@args_token: pointer to a segmented input string
* **@copy_path: copy of env PATH
* Description: Struct contain all shell info.
* This one struct will be passed from func to func and contain
* all the shell info for the current session.
*/
typedef struct inputdata
{
	char *inputarray; /* saves input from terminal  (getline) */
	size_t inputsize; /* saves size of input from terminal (getline)*/
	char *args_token[1024]; /*Tokenized inputarray */
	char *copy_path;	/* Entire PATH without PATH= */
	char *tokenized_path[1024]; /*Tokenized PATH*/
	int promptcounter; /* counts number of input user commands*/
	int wexitreturn; /*Integer that saves a flag that returns an exit*/
} inputdata_t;

/* Function to display a prompt and return the input value */
int promptdisplay(inputdata_t *data);

/* Function that tokenize input string to save it into structure */
void _strtok(inputdata_t *data);

/* Copy environ and search for path into the copy. */
char *getpath(void);

/*Function that tokenize the path*/
int strtok_path(inputdata_t *data);

/* Function that create a child and execute the pathname*/
int pid_ppid(inputdata_t *data);

/*function that create a child, execute the pathname and concatenate with input*/
int path_pid_ppid(inputdata_t *data);

/* concat_temp - Concatenation temporal to check path */
char *concat_temp(inputdata_t *data, int j);

/* Function that compares two strings  */
int _strequal(char *s1, char *s2);

/* Function that concatenates two strings */
char *_strcat(char *dest, char *src);

/*function that count the number of characters*/
int StringLenght(char *string);

/*		BUILT INS		*/
/**
* struct builtin - shell structure to save builtin
* *@type: pointer to a string to compare input builtins
* *@f: pointer to a function to run builtins
* Description: Struct that contains builtins
*/
typedef struct builtin
{
	char *type;
	int (*f)(inputdata_t *data);
} built_in;

/*builtin that emulates the command to exit from mini-shell*/
int sh_exit(inputdata_t *data);

/*		_PRINTF		*/

int _printf(int fd, const char *format, ...);

/* Function that fills place holders with string */
int print_c(va_list parameters, int j, char *join);
/* function that fills place holders with string */
int print_s(va_list parameters, int j, char *join);

/* function that fills place holders with string */
int print_n(va_list parameters, int j, char *join);
/**
 *  struct placeHolders- typedef struct
 * @type:type of place holders
 * @f:pointer to funtion
 **/
typedef struct placeHolders
{
	char *type;
	int (*f)(va_list, int, char *);
} place_holders;

#endif /* H_SHELL */
