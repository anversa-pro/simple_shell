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
	free(data->copy_path);
	free(data->inputarray);
	exit(data->wexitreturn);
}
