#include "shell.h"

/* FUNCTION STRINGS - 1 */
/**
 * strtok_path - Function that tokenize the path.
 * @string: Pointer to global structure
 * Return: Success status
 */
int StringLenght(char *string)
{
	int i = 0;

	while (string[i])
	{
		i++;
	}
	return (i);
}
/* FUNCTION STRINGS - 2 */
/**
 * _strequal - compares two strings
 * *@s1: input array to compare
 * *@s2: input array to compare
 * Return: 0 if diference 1 if equal
 */

int _strequal(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return (0);
		}
		i++;
	}
	return (1);
}
/* FUNCTION STRINGS - 3 */
/**
 * _strcat - concatenates two strings
 * *@dest: input array to add content
 * *@src: input array to append
 * Return: dest
 */
char *_strcat(char *dest, char *src)
{
	int i;
	int j = 0;

	while (dest[j] != '\0')
	{
		j++;
	}
	for (i = 0; src[i] != '\0'; ++i, ++j)
	{
		dest[j] = src[i];
	}
	dest[j] = '\0';
	return (dest);
}
