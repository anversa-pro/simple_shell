#include "shell.h"

/* FUNCTION 02 - A */
/**
 * str_startwith - Search for a string into a string
 * *@env: Pointer to copy of environ
 * *@string_to_check: String to search into env
 * Return: address to a position of string
 */
int str_startwith(char *env, char *string_to_check)
{
	int j = 0, c = 0;

	for (j = 0; env[j] >= '\0'; j++)
	{
		for (c = 0; string_to_check[c] >= '\0'; c++)
		{
			if (env[j + c] != string_to_check[c])
			{
				break;
			}
		}
		if (!string_to_check[c])
		{
			return ((&env[j]) == env);
		}
	}
	return (0);
}

/* FUNCTION 02 - B */
/**
 * *getPath - Copy environ and search for path into the copy.
 * Return: Pointer to a Path or NULL if not found.
 */
char *getPath()
{
	char **env = environ;

	for (; *env; env++)
	{
		/* ("%s\n", *env); */
		if (str_startwith(*env, "PATH="))
			return (strdup((*env) + 5));
	}
	return (NULL);
}
/* FUNCTION 02 - C */
/**
 * strtokPath - Function that tokenize the path.
 * *@data: Pointer to global structure
 * Return: Success status
 */
int strtokPath(inputData_t *data)
{
	char *text = data->copyPath;
	char *tmp;
	int i = 0;

	data->tokenizedPath[0] = strtok(text, DELIM2);
	i++;
	tmp = text;
	while (tmp != NULL)
	{
		tmp = strtok(NULL, DELIM2);
		data->tokenizedPath[i] = tmp;
		i++;
	}
	return (0);
}
