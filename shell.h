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
* struct inputData - shell structure to save and manage info and args
* *@nameExecutable: Executable name
* *@inputArray: pointer to a copy of terminal input string
* @inputSize: size of terminal input string
* *@argsToken: pointer to a segmented input string
* *@copyPath: copy of env PATH
* *@tokenizedPath: Poiter to the entire PATH without PATH=
* @promptCounter: counts number of input user commands
* @wexitStat: Integer that saves a flag that returns an exit
* Description: Struct contain all shell info.
* This one struct will be passed from func to func and contain
* all the shell info for the current session.
*/
typedef struct inputData
{
	char *nameExecutable;
	char *inputArray; /* saves input from terminal  (getline) */
	size_t inputSize; /* saves size of input from terminal (getline)*/
	char *argsToken[1024]; /*Tokenized inputArray */
	char *copyPath;	/* Entire PATH without PATH= */
	char *tokenizedPath[1024]; /*Tokenized PATH*/
	int promptCounter; /* counts number of input user commands */
	int wexitStat; /* Integer that saves a flag that returns an exit */
} inputData_t;

/* Function to display a prompt and return the input value */
int promptDisplay(inputData_t *data);

/* Function that tokenize input string to save it into structure */
void _strtok(inputData_t *data);

/* Copy environ and search for path into the copy. */
char *getPath(void);

/* Function that tokenize the path*/
int strtokPath(inputData_t *data);

/* Function that create a child and execute the pathname*/
int _pid(inputData_t *data, char *);

/* Create a child, execute the pathname and concatenate with input*/
int pathConcat(inputData_t *data);

/* Concatenation temporal to check path */
char *concatTemp(inputData_t *data, int j);

/* Function that compares two strings  */
int _strequal(char *s1, char *s2);

/* Function that concatenates two strings */
char *_strcat(char *dest, char *src);

/* Function that count the number of characters*/
int stringLenght(char *string);

/* Function that verify access of falie every its called */
int accessHandler(inputData_t *data);

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
	int (*f)(inputData_t *data);
} builtIn_t;

/*builtin that emulates the command to exit from mini-shell*/
int sh_exit(inputData_t *data);

/*builtin that emulates the command to exit from mini-shell*/
int sh_env(inputData_t *data);

/*		_PRINTF		*/
/* Function that emulates printf */
int _printf(int fd, const char *format, ...);

/* Function that fills place holders with string */
int _printC(va_list parameters, int j, char *join);

/* Function that fills place holders with string */
int _printS(va_list parameters, int j, char *join);

/* Function that fills place holders with string */
int _printN(va_list parameters, int j, char *join);

/**
 *  struct placeHolders- typedef struct
 * @type:type of place holders
 * @f:pointer to funtion
 **/
typedef struct placeHolders
{
	char *type;
	int (*f)(va_list, int, char *);
} placeHolders_t;

#endif /* H_SHELL */
