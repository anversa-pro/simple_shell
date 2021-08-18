#ifndef H_SHELL
#define H_SHELL

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
/* global variable that extract env of system*/
extern char **environ;
/**
 * struct sev_s - shell env vars

 * Description: Struct contain all shell env vars.
 * This one struct will be passed from func to func and contain
 * all the shell env vars for the current session.
 */
typedef struct inputdata
{
	char* inputarray;
	size_t inputsize;
	char** copy_path;
} inputdata_t;


/*function to display a prompt and return the input value*/
int promptdisplay(inputdata_t *data);

/*function that prints all arguments*/
char *_strtok(inputdata_t *data);

/*function that do a copy of the PATH*/
int strtok_path(inputdata_t *data);

/*function that create a child and execute the pathname*/
int pid_ppid(inputdata_t *data);

#endif /* H_SHELL */