#include "shell.h"

/**/
void sigint_handler(int number __attribute__((unused)))
{
	signal(SIGINT, sigint_handler);
	_printf(STDOUT_FILENO, "\n%s", PROMPT);
	fflush(stdout);
}

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
	signal(SIGINT, sigint_handler);

	built_in builtin_function[] = {
		{"exit", sh_exit}, {NULL, NULL}};
	glData.promptcounter = 0;
	glData.inputarray = NULL;
	glData.inputsize = 0;


	while (checkprompt != -1) /* Checks if its EOF*/
	{
		checkprompt = promptdisplay(&glData);
		if (checkprompt == -1)
		{
			break;
		}
		/* Tokenize input string and saves it into global structure*/
		_strtok(&glData);
		/**si existe el archivo ejecuta el hijo*/
		if (!glData.args_token[0])
			continue;
		if (access(glData.args_token[0], F_OK) == 0)
		{
			pid_ppid(&glData); /* Creates child process to excecute tokenized arg */
			continue;
		}
		glData.copy_path = getpath(); /* Cp env & find the path*/
		strtok_path(&glData); /* Tokenize path to find the directory */
		for (k = 0; builtin_function[k].f; k++)
		{
			if (_strequal(builtin_function[k].type, glData.args_token[0]))
			{
				builtin_function[k].f(&glData);
				free(glData.copy_path);
				continue;
			}
		}
		path_pid_ppid(&glData);
		free(glData.copy_path);
	}
	free(glData.inputarray);
	if (isatty(STDIN_FILENO))
		write(1, "\n", 1);
}
