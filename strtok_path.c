#include "shell.h"
#define STRTOK_TEST
/**
 * strtok_path - Function that tokenize the path.
 * *@data: Pointer to global structure
 * Return: Success status
 */
int strtok_path(inputdata_t *data)
{
	char **text = data->copy_path;
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
