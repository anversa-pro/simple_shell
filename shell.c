#include "shell.h"
/**
 * main - the holberton shell program
 * Return: 0 in success, everything else is an error
 */
int main(void)
{
	int checkprompt = 0;
	inputdata_t glData = {};
	int k = 0;
	char *copy_string;
	int j = 0;

	built_in builtin_function[] = {
		{"exit", sh_exit},
		{NULL, NULL}};
	/**{"env", _env},*/
	/**{"exec", _exec},
		{"setenv", _setenv},
		{"unsetenv", _unsetenv},*/

	/* Checks if its EOF*/
	glData.promptcounter = 0;
	while (checkprompt != -1)
	{
		checkprompt = promptdisplay(&glData);
		if (checkprompt == -1)
		{
			break;
		}
		/* Tokenize input string and saves it into global structure*/
		_strtok(&glData);
		/* Creates child process to excecute tokenized arg */
		pid_ppid(&glData);
		/* Copies the environment & find the path*/
		glData.copy_path = getpath(); /*Remember to free copy path*/
		/*printf("%s\n\n", glData.copy_path); */
		/* Tokenize path to find the directory */
		strtok_path(&glData);
		path_pid_ppid(&glData);

		while(!k)
		{
			if (builtin_function[k].type[0] == *glData.args_token[0])
			{
				builtin_function[k].f(&glData);
			}
			k++;
		}
		free(glData.copy_path);
	}
	if (isatty(STDIN_FILENO))
		write(1, "\n", 1);
}
