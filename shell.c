#include "shell.h"
/**
 * main - the holberton shell program
 * Return: int result. 0 in success, everything else is an error
 */
int main(void)
{
	int checkprompt;
	inputdata_t glData = {};
	char **maintoken;
	int i = 0;
	built_in builtin_function[] = {
			    {"exit", _exit},
			    {"exec", _exec}, 
			    {"env", _env}, 
			    {"setenv", _setenv}, 
			    {"unsetenv", _unsetenv}, 
			    {NULL, NULL}};

	/* Checks if its EOF*/
	while (checkprompt != -1)
	{
		checkprompt = promptdisplay(&glData);
		maintoken=_strtok(&glData);
		while (i != NULL)
		{
			if ()
		}
		pid_ppid(&glData);
		//strtok_path(&glData);
	}
	printf("Tokenizar");
	/*  */
	/*  */
}
