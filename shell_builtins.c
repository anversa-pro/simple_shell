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

/* BUILTINS 01 - B */
/**
 * sh_env - Emulates command env.
 * *@data: Pointer to global structure
 * Return: to define.
 */
int _env(inputdata_t *data)
{
	(void)data;
	printf("Into env function");

	return (0);
}

/* BUILTINS 01 - C */
/**
 * sh_exec - Emulates command exec.
 * *@data: Pointer to global structure
 * Return: to define.
 */
/**int sh_exec(inputdata_t *data)
{
	(void)data;
	printf("Into exec function");

	return (0);
}*/

/* BUILTINS 01 - D */
/**
 * sh_setenv - Emulates command setenv.
 * *@data: Pointer to global structure
 * Return: to define.
 */
/**int sh_setenv(inputdata_t *data)
{
	(void)data;
	printf("Into setenv function");

	return (0);
}*/

/* BUILTINS 01 - E */
/**
 * sh_unsetenv - Emulates command unsetenv.
 * *@data: Pointer to global structure
 * Return: to define.
 */
/**int sh_unsetenv(inputdata_t *data)
{
	(void)data;
	printf("Into unsetenv function");

	return (0);
}*/
