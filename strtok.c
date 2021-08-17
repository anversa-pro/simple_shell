#include "shell.h"

/**
 * main - Prints all arguments
 *
 * @ac: is the number of items in av
 * @av: is a NULL terminated array of strings
 *
 * Return: Success status
 */
int _strtok(inputdata_t *data)
{
	char *text = data->inputarray;
	char *token;

	token = strtok(text, DELIM);

	while (token != NULL)
	{
		printf("%s\n", token);
		token = strtok(NULL, DELIM);
	}
	return (0);
}
