#include "shell.h"
/**
 * main - the holberton shell program
 * Return: int result. 0 in success, everything else is an error
 */
int main(void)
{
	int checkprompt;
	inputdata_t glData = {};

	/* Checks if its EOF*/
	while (checkprompt != -1)
	{
		checkprompt = promptdisplay(&glData);
		_strtok(&glData);
		pid_ppid(&glData);
		//strtok_path(&glData);
	}
	printf("Tokenizar");
	/*  */
	/*  */
}
