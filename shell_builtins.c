#include "shell.h"

/* BUILTINS 01 - A */
/**
 * sh_exit - Emulates command exit.
 * *@data: Pointer to global structure
 * Return: to define.
 */
int sh_exit(inputdata_t *data)
{
	(void)data;
	free(data->inputarray);
	exit(data->wexitreturn);
}
/* BUILTINS 01 - A */
/**
 * sh_env - Emulates command exit.
 * *@data: Pointer to global structure
 * Return: to define.
 */
int sh_env(inputdata_t *data)
{
	int i = 0;

	(void)data;

	for (; environ[i]; i++)
	{
		_printf(1, "%s\n", environ[i]);
	}
	return (0);
}
