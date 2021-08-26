#include "shell.h"

/* BUILTINS 01 - A */
/**
 * sh_exit - Emulates command exit.
 * *@data: Pointer to global structure
 * Return: to define.
 */
int sh_exit(inputData_t *data)
{
	(void)data;
	free(data->inputArray);
	exit(data->wexitStat);
}
/* BUILTINS 01 - A */
/**
 * sh_env - Emulates command exit.
 * *@data: Pointer to global structure
 * Return: to define.
 */
int sh_env(inputData_t *data)
{
	int i = 0;

	(void)data;

	for (; environ != NULL && environ[i]; i++)
		_printf(1, "%s\n", environ[i]);

	if (i <= 1)
		data->wexitStat = 0;

	return (0);
}
