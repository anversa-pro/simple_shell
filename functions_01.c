#include "shell.h"

/* FUNCTION 01 - A */
/**
 * promptdisplay - Prints prompt while holberton shell is running
 * @data: Pointer to global structure
 * Return: quantity of characters readed
 */
int promptdisplay(inputdata_t *data)
{
	int charactersRead = 0;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, PROMPT, StringLenght(PROMPT));
	charactersRead = getline(&(data->inputarray), &(data->inputsize), stdin);
	if (charactersRead > 0)
		data->inputarray[charactersRead - 1] = '\0';
	data->promptcounter++;

	return (charactersRead);
}

/* FUNCTION 01 - B */
/**
 * _strtok - Tokenize input string to save it into structure
 * *@data: Pointer to global structure
 * Return: void
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

/* FUNCTION 01 - C */
/**
 * pid_ppid - Creates child process to excecute tokenized arg copy
 * *@data: Pointer to global structure
 * *@dircommand: pointer to user input arg[0]
 * Return: Success status
 */
int pid_ppid(inputdata_t *data, char *dircommand)
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
		execve(dircommand, data->args_token, environ);
	}
	else
	{
		wait(&status); /* se creo el papa */
		data->wexitreturn = WEXITSTATUS(status);
	}
	return (0);
}

/* FUNCTION 01 - D */
/**
 * path_pid_ppid - Creates child process to execute & find PATH
 * *@data: Pointer to global structure
 * Return: Success status
 */
int path_pid_ppid(inputdata_t *data)
{
	int i = 0, j = 0;
	char *temp_path;
	struct stat sb;

	for (; data->tokenized_path[j] != NULL; j++)
	{
		temp_path = concat_temp(data, j);
		if ((stat(temp_path, &sb) == 0) && i != 1)
		{
			if (pid_ppid(data, temp_path))
			{
				free(temp_path);
				return (1);
			}
			i = 1;
		}
		free(temp_path);
	}
	if (i == 0)
	{
		data->wexitreturn = 127;
		_printf(2, "%s: %d: %s: not found\n", data->nameExecutable,
		data->promptcounter, data->args_token[0]);
		return (-1);
	}
	return (0);
}

/* FUNCTION 01 - E */
/**
 * concat_temp - Concatenation temporal to check path
 * *@data: Pointer to global structure
 * @j: integer for locate tokenized path position
 * Return: Success status
 */
char *concat_temp(inputdata_t *data, int j)
{
	int numtkpath = 0, numtktoken = 0;
	char *temp_path;

	numtkpath = StringLenght(data->tokenized_path[j]);
	numtktoken = StringLenght(data->args_token[0]);
	temp_path = malloc(sizeof(char *) * (numtkpath + numtktoken + 1));
	temp_path[0] = '\0';
	_strcat(temp_path, data->tokenized_path[j]);
	_strcat(temp_path, SLASH);
	_strcat(temp_path, data->args_token[0]);
	return (temp_path);
}
