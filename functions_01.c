#include "shell.h"

/* FUNCTION 01 - A */
/**
 * promptDisplay - Prints prompt while holberton shell is running
 * @data: Pointer to global structure
 * Return: quantity of characters readed
 */
int promptDisplay(inputData_t *data)
{
	int charactersRead = 0;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, PROMPT, stringLenght(PROMPT));
	charactersRead = getline(&(data->inputArray), &(data->inputSize), stdin);
	if (charactersRead > 0)
		data->inputArray[charactersRead - 1] = '\0';
	data->promptCounter++;

	return (charactersRead);
}

/* FUNCTION 01 - B */
/**
 * _strtok - Tokenize input string to save it into structure
 * *@data: Pointer to global structure
 * Return: void
 */
void _strtok(inputData_t *data)
{
	char *text = data->inputArray;
	char *tmp;
	int i = 0;

	data->argsToken[0] = strtok(text, DELIM);
	i++;
	tmp = text;
	while (tmp != NULL)
	{
		tmp = strtok(NULL, DELIM);
		data->argsToken[i] = tmp;
		i++;
	}
}

/* FUNCTION 01 - C */
/**
 * _pid - Creates child process to excecute tokenized arg copy
 * *@data: Pointer to global structure
 * *@dirCommand: pointer to user input arg[0]
 * Return: Success status
 */
int _pid(inputData_t *data, char *dirCommand)
{
	pid_t pid;
	int status = 0;

	pid = fork();
	if (pid == -1)
	{
		perror("Error:"); /* no se creo el hijo */
		return (1);
	}
	if (pid == 0)
	{
		if (execve(dirCommand, data->argsToken, environ) == -1)
		{
			perror("Error:");
			return (1);
		}
	}
	else
	{
		wait(&status); /* se creo el papa */
		data->wexitStat = WEXITSTATUS(status);
	}
	return (0);
}

/* FUNCTION 01 - D */
/**
 * pathConcat - Creates child process to execute & find PATH
 * *@data: Pointer to global structure
 * Return: Success status
 */
int pathConcat(inputData_t *data)
{
	int i = 0, j = 0;
	char *tempPath;
	struct stat sb;

	for (; data->tokenizedPath[j] != NULL; j++)
	{
		tempPath = concatTemp(data, j);
		if ((stat(tempPath, &sb) == 0) && i != 1)
		{
			if (_pid(data, tempPath))
			{
				free(tempPath);
				return (1);
			}
			i = 1;
		}
		free(tempPath);
	}
	if (i == 0)
	{
		data->wexitStat = 127;
		_printf(2, "%s: %d: %s: not found\n", data->nameExecutable,
		data->promptCounter, data->argsToken[0]);
	}
	return (0);
}

/* FUNCTION 01 - E */
/**
 * concatTemp - Concatenation temporal to check path
 * *@data: Pointer to global structure
 * @j: integer for locate tokenized path position
 * Return: Success status
 */
char *concatTemp(inputData_t *data, int j)
{
	int numTkPath = 0, numTkToken = 0;
	char *tempPath;

	numTkPath = stringLenght(data->tokenizedPath[j]);
	numTkToken = stringLenght(data->argsToken[0]);
	tempPath = malloc(sizeof(char *) * (numTkPath + numTkToken + 1));
	tempPath[0] = '\0';
	_strcat(tempPath, data->tokenizedPath[j]);
	_strcat(tempPath, SLASH);
	_strcat(tempPath, data->argsToken[0]);
	return (tempPath);
}
