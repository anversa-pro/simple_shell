#include "shell.h"

/**
 * main - Prints all arguments
 *
 * Return: Success status
 */
int promptdisplay(inputdata_t *data)
{
	char *line = NULL;
	size_t lineSize = 0;
	int charactersRead = 0;
	
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, PROMPT, strlen(PROMPT));
	charactersRead = getline(&line, &lineSize, stdin);
	line[charactersRead - 1] = '\0';
	//write(STDOUT_FILENO, line, charactersRead);
	data->inputarray = line;
	data->inputsize = lineSize;

	return (charactersRead);
}
