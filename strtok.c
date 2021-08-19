#include "shell.h"
/**
 * main - Prints all arguments
 *
 * @ac: is the number of items in av
 * @av: is a NULL terminated array of strings
 *
 * Return: Success status
 */
void _strtok(inputdata_t *data)
{
    char *text = data->inputarray;
    char *tmp;
    int i = 0;

    data->args_token[0] = strtok(text, DELIM);
    i++;
    tmp = text;
    while (tmp != NULL)
    {
        tmp = strtok(NULL, DELIM);
        data->args_token[i] = tmp;
        i++;
    }
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
