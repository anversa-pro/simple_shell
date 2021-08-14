#include <stdio.h>
#include <unistd.h>
#include <string.h>
/**
 * main - Prints all arguments
 *
 * @ac: is the number of items in av
 * @av: is a NULL terminated array of strings
 *
 * Return: Success status
 */
int main(void)
{
	char *prompt = "$ ";
	char *line;
	size_t lineSize = 0;
	int charactersRead = 0;

	while (1)
	{
		write(STDOUT_FILENO, prompt, strlen(prompt));
		charactersRead = getline(&line, &lineSize, stdin);
		write(STDOUT_FILENO, line, charactersRead);
	}
	return (0);
}
