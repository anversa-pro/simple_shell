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
	char *inputarray;
	size_t inputsize;
	char *args_token[1024];
	char *copy_path;	/* Entire PATH without PATH= */
	char *tokenized_path[1024]; /*Tokenized PATH*/
	int promptcounter;
	int wexitreturn;
} inputdata_t;

/*function to display a prompt and return the input value*/
int promptdisplay(inputdata_t *data);

/*function that prints all arguments*/
void _strtok(inputdata_t *data);

/*function that do a copy of the PATH*/
int strtok_path(inputdata_t *data);

/*function that create a child and execute the pathname*/
int pid_ppid(inputdata_t *data);

/* Copy environ and search for path into the copy. */
char *getpath(void);

/*function that create a child, execute the pathname and concatenate with input*/
int path_pid_ppid(inputdata_t *data);

/* _strequal - compares two strings */
int _strequal(char *s1, char *s2);

/* _strcat - concatenates two strings */
char *_strcat(char *dest, char *src);

/*function that count the number of characters*/
int StringLenght(char *string);

/* concat_temp - Concatenation temporal to check path */
char *concat_temp(inputdata_t *data, int j);

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

/*function that create a child and execute the pathname*/
int sh_exit(inputdata_t *data);

int _printf(int fd, const char *format, ...);
int print_c(va_list parameters, int j, char *join);
int print_s(va_list parameters, int j, char *join);
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

/*function that create a child and execute the pathname*/
//int _exec(inputdata_t *data, char **);
/*Initialize a new environment variable
//int _setenv(inputdata_t *data, char **);
/*Remove an environment variable*/
//int _unsetenv(inputdata_t *data, char **);
/*Remove an environment variable*/
//int _cd(inputdata_t *data, char **);
/*Remove an environment variable*/
//int _alias(inputdata_t *data, char **);

#endif /* H_SHELL */
