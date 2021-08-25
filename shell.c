#include "shell.h"

/**
* sigint_handler - gets and interrupt the keyboard input if CTRL+ C
* @number: flag for signal
* Return: void
*/
void sigint_handler(int number __attribute__((unused)))
{
	signal(SIGINT, sigint_handler);
	_printf(STDOUT_FILENO, "\n%s", PROMPT);
	fflush(stdout);
}

/**
 * main - the holberton shell program
 * @argc: number of arguments
 * **@argv: double pointer to arguments
 * Return: 0 in success, everything else is an error
 */
int main(int argc __attribute__((unused)), char *argv[])
{
	int checkprompt = 0, k = 0;
	inputdata_t glData = {NULL};
	built_in builtin_function[] = {
		{"exit", sh_exit}, {"env", sh_env}, {NULL, NULL}};

	signal(SIGINT, sigint_handler);

	glData.promptcounter = 0, glData.inputarray = NULL;
	glData.inputsize = 0, glData.nameExecutable = argv[0];

	while (checkprompt != -1) /* Checks if its EOF*/
	{
		checkprompt = promptdisplay(&glData);
		if (checkprompt == -1)
			break;
		_strtok(&glData); /* Tokenize input and saves into glData*/
		for (k = 0; builtin_function[k].f; k++)
			if (_strequal(builtin_function[k].type, glData.args_token[0]))
			{
				builtin_function[k].f(&glData);
				continue;
			}
		if (!glData.args_token[0]) /* Token is different from null*/
			continue;
		if (access_handler(&glData) == 0)
			continue;
		/* DELETED LINE */
		glData.copy_path = getpath(); /* Cp env & find the path*/
		strtok_path(&glData); /* Tokenize path to find the directory */
		path_pid_ppid(&glData);
		free(glData.copy_path);
	}
	free(glData.inputarray);
	if (isatty(STDIN_FILENO))
		write(1, "\n", 1);
	return (glData.wexitreturn);
}
