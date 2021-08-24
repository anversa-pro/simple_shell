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
	int j;
	int c;

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
 * *getpath - Copy environ and search for path into the copy.
 * Return: Pointer to a Path or NULL if not found.
 */
char *getpath()
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
 * strtok_path - Function that tokenize the path.
 * *@data: Pointer to global structure
 * Return: Success status
 */
int strtok_path(inputdata_t *data)
{
	char *text = data->copy_path;
	char *tmp;
	int i = 0;

	data->tokenized_path[0] = strtok(text, DELIM2);
	/* printf("token posicion i %d %s\n", i, data->tokenized_path[0]); */
	i++;
	tmp = text;
	while (tmp != NULL)
	{
		tmp = strtok(NULL, DELIM2);
		data->tokenized_path[i] = tmp;
		i++;
	}
	return (0);
}
