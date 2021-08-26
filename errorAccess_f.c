#include "shell.h"

/**
 * accessHandler - Verifies access of falie every its called
 * *@data: pointer to global structure
 * Return: 0 in success or -1 otherwise
 */
int accessHandler(inputData_t *data)
{
	if (access(data->argsToken[0], F_OK) == 0)
	{
		_pid(data, data->argsToken[0]);
		return (0);
	}
	return (-1);
}
