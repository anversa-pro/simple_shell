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
		{"env", _env},
		{NULL, NULL}};
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
		/**si existe el archivo ejecuta el hijo*/
		if(access(glData.args_token[0], F_OK) == 0)
		{
			/* Creates child process to excecute tokenized arg */
			pid_ppid(&glData);
			continue;
		}
		/* Copies the environment & find the path*/
		glData.copy_path = getpath(); /*Remember to free copy path*/
		/* Tokenize path to find the directory */
		strtok_path(&glData);
		while(!k)
		{
			if (builtin_function[k].type[0] == *glData.args_token[0])
			{
				builtin_function[k].f(&glData);
				continue;
			}
			k++;
		}
		/*printf("%s\n\n", glData.copy_path); */
		path_pid_ppid(&glData);
		free(glData.copy_path);
	}
	if (isatty(STDIN_FILENO))
		write(1, "\n", 1);
}
