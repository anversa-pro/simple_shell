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
int main()
{
	char text[] = "hola;chao";
	const char *DELIM = ";";
	char *token;

	token = strtok(text, DELIM);

	while (token != NULL)
	{
		printf("%s\n", token);
		token = strtok(NULL, DELIM);
	}
	return (0);
}
