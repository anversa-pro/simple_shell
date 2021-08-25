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

/*		MACROS		*/
#define PROMPT "$ "
#define DELIM " "
#define DELIM2 ":"
#define SLASH "/"
#define DENIED "Permission denied\n" /* REVIEWTONEWFILE*/
#define TOOLONG "File name too long\n" /* REVIEWTONEWFILE*/
#define NREAD "Permission denied \n" /* REVIEWTONEWFILE*/
#define NFOUND "not found\n" /* REVIEWTONEWFILE*/
/*		MAIN		*/
/* global variable that extract env of system*/
extern char **environ;
/**
* struct inputdata - shell structure to save and manage info and args
* *@nameExecutable: Executable name
* *@inputarray: pointer to a copy of terminal input string
* @inputsize: size of terminal input string
* *@args_token: pointer to a segmented input string
* *@copy_path: copy of env PATH
* *@tokenized_path: Poiter to the entire PATH without PATH=
* @promptcounter: counts number of input user commands
* @wexitreturn: Integer that saves a flag that returns an exit
* Description: Struct contain all shell info.
* This one struct will be passed from func to func and contain
* all the shell info for the current session.
*/
typedef struct inputdata
{
	char *nameExecutable;
	char *inputarray; /* saves input from terminal  (getline) */
	size_t inputsize; /* saves size of input from terminal (getline)*/
	char *args_token[1024]; /*Tokenized inputarray */
	char *copy_path;	/* Entire PATH without PATH= */
	char *tokenized_path[1024]; /*Tokenized PATH*/
	int promptcounter; /* counts number of input user commands */
	int wexitreturn; /* Integer that saves a flag that returns an exit */
} inputdata_t;

/* Function to display a prompt and return the input value */
int promptdisplay(inputdata_t *data);

/* Function that tokenize input string to save it into structure */
void _strtok(inputdata_t *data);

/* Copy environ and search for path into the copy. */
char *getpath(void);

/* Function that tokenize the path*/
int strtok_path(inputdata_t *data);

/* Function that create a child and execute the pathname*/
int pid_ppid(inputdata_t *data, char *);

/* Create a child, execute the pathname and concatenate with input*/
int path_pid_ppid(inputdata_t *data);

/* Concatenation temporal to check path */
char *concat_temp(inputdata_t *data, int j);

/* Function that compares two strings  */
int _strequal(char *s1, char *s2);

/* Function that concatenates two strings */
char *_strcat(char *dest, char *src);

/* Function that count the number of characters*/
int StringLenght(char *string);

/* Function that verify access of falie every its called */
int access_handler(inputdata_t *data);

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

/*builtin that emulates the command to exit from mini-shell*/
int sh_env(inputdata_t *data);
/*		_PRINTF		*/
/* Function that emulates printf */
int _printf(int fd, const char *format, ...);

/* Function that fills place holders with string */
int print_c(va_list parameters, int j, char *join);

/* Function that fills place holders with string */
int print_s(va_list parameters, int j, char *join);

/* Function that fills place holders with string */
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
