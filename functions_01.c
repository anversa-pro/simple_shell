#include "shell.h"

/* FUNCTION 01 - A */
/**
 * promptdisplay - Prints prompt while holberton shell is running
 * *@data: Pointer to global structure
 * Return: quantity of characters readed
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
	data->inputarray = line;
	data->inputsize = lineSize;
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
 * pid_ppid - Creates child process to excecute tokenized arg
 * *@data: Pointer to global structure
 * Return: Success status
 */
int pid_ppid(inputdata_t *data)
{
	pid_t pid;
	int status = 0, i = 0;
	int execute;
	int c = 0;
	/*
	* while (data->args_token[i] != NULL)
	* {
	*	printf("./s""hell: No such file or directory\n");
	* 	i++;
	*}
	*/
	pid = fork();
	if (pid == -1)
	{
		perror("Error:"); /* no se creo el hijo */
		return (1);
	}
	if (pid == 0)
	{
		execute = execve(data->args_token[0], data->args_token, NULL);
		if (execute == -1)
			exit(98);
	}
	else
		wait(&status); /* se creo el papa */
	pid = getpid();
	return (0);
}

/* FUNCTION 01 - D */
/**
 * pid_ppid - Creates child process to execute & find PATH
 * *@data: Pointer to global structure
 * Return: Success status
 */
int path_pid_ppid(inputdata_t *data)
{
	pid_t pid;
	int status = 0, i = 0, j = 0;
	int execute;
	char *temp_path;
	char *slash = "/";
	struct stat sb;
	/*
	* while (data->args_token[i] != NULL)
	* {
	*	printf("./s""hell: No such file or directory\n");
	* 	i++;
	*}
	*/
	for (; data->tokenized_path[j] != NULL; j++)
	{
		temp_path = malloc(sizeof(char*) * (strlen(data->tokenized_path[j]) + strlen(data->args_token[0]) + 1));
		strcat(temp_path, data->tokenized_path[j]);
		strcat(temp_path, slash);
		strcat(temp_path, data->args_token[0]);

		if ((stat(temp_path, &sb) == 0) && i != 1)
		{
			pid = fork();
			if (pid == -1)
			{
				perror("Error:"); /* no se creo el hijo */
				return (1);
			}
			if (pid == 0)
			{
				execute = execve(temp_path, data->args_token, NULL);
				if (execute == -1)
					exit(98);
			}
			else
			{
				wait(&status); /* se creo el papa */
				i = 1;
			}
			pid = getpid();
		}
		free (temp_path);
	}
	if (i == 0)
	{
		/**si la primera palabra no se encuentra*/
		printf("sh : %d: %s: not found\n", data->promptcounter, data->args_token[0]);
		return(-1);
	}
	return (0);
}
