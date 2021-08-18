#include "shell.h"
/**
 * main - Prints all arguments
 *
 * @ac: is the number of items in av
 * @av: is a NULL terminated array of strings
 *
 * Return: Success status
 */
char *_strtok(inputdata_t *data)
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
	return (*token);
}
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
			return ((&env[j])==env);
		}
	}
	return (0);
}
//enter to env, get path and return a pointer to copy of path
char *getpath()
{
  char **env = environ;

  for (; *env; env++)
  {
    //printf("%s\n", *env);
	if (str_startwith(*env, "PATH="))
	{
		return(strdup((*env) + 5));
	}
  }
  return NULL;
}
