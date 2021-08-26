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
	int checkPrompt = 0, k = 0;
	inputData_t glData = {NULL};
	builtIn_t builtinFunction[] = {
		{"exit", sh_exit}, {"env", sh_env}, {NULL, NULL}};

	signal(SIGINT, sigint_handler);

	glData.promptCounter = 0, glData.inputArray = NULL;
	glData.inputSize = 0, glData.nameExecutable = argv[0];

	while (checkPrompt != -1) /* Checks if its EOF*/
	{
		checkPrompt = promptDisplay(&glData);
		if (checkPrompt == -1)
			break;
		_strtok(&glData); /* Tokenize input and saves into glData*/
		for (k = 0; builtinFunction[k].f; k++)
			if (_strequal(builtinFunction[k].type, glData.argsToken[0]))
			{
				builtinFunction[k].f(&glData);
				glData.argsToken[0] = NULL;
				break;
			}
		if (!glData.argsToken[0]) /* Token is different from null*/
			continue;
		if (accessHandler(&glData) == 0)
			continue;
		/* DELETED LINE */
		glData.copyPath = getPath(); /* Cp env & find the path*/
		strtokPath(&glData); /* Tokenize path to find the directory */
		pathConcat(&glData);
		free(glData.copyPath);
	}
	free(glData.inputArray);
	if (isatty(STDIN_FILENO))
		write(1, "\n", 1);
	return (glData.wexitStat);
}
