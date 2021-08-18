#include "shell.h"
/**
 * main - Prints all arguments
 *
 * Return: Success status
 */
int pid_ppid(inputdata_t *data)
{
	char *return_strtok = _strtok(data);
	pid_t my_pid;
    pid_t pid;
	int status = 0;

    printf("Before fork\n");
    pid = fork();
    if (pid == -1)
    {
        perror("Error:");//no se creo el hijo
        return (1);
    }
	if (pid == 0)
    {
        printf("se creo el hijo\n");// se creo el hijo
		execve(return_strtok, &return_strtok, NULL);
    }
	else
	{
		wait(&status);//se creo el papa

	}
    printf("After fork\n");
    my_pid = getpid();
    printf("My pid is %u\n", my_pid);
    return (0);
	//revisar porque no esta haciendo el execve
}
/**
 * main - Prints all arguments
 *
 * Return: Success status
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
	//write(STDOUT_FILENO, line, charactersRead);
	data->inputarray = line;
	data->inputsize = lineSize;

	return (charactersRead);
}
