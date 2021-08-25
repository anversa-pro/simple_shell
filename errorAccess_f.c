#include "shell.h"

/**
 * access_handler - Verifies access of falie every its called
 * *@data: pointer to global structure
 * Return: 0 in success or -1 otherwise
 */
int access_handler(inputdata_t *data)
{
	if (access(data->args_token[0], F_OK) == 0)
	{
		pid_ppid(data, data->args_token[0]);
		return (0);
	}
	return (-1);
}
