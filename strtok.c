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
	char *token[2048];
	char *tmp;
	int i = 0;

	token[0] = strtok(text, DELIM);
	printf("token posicion i %d %s\n", i, token[0]);
	i++;
	tmp = text;
	while (tmp != NULL)
	{
		tmp = strtok(NULL, DELIM);
		token[i] = tmp;
		printf("token posicion i %d %s\n", i, token[i]);
		i++;
	}
	return (0);
}
