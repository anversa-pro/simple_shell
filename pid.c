#include <stdio.h>
#include <unistd.h>

/**
 * main - PID
 *
 * Return: Always 0.
 */
int main(void)
{
	pid_t my_pid;
	int i = 0;

	my_pid = getpid();
	while (i < 3)
	{
		printf("%u\n", my_pid);
		printf("%u\n", getppid());
		i++;
	}
	return (0);
}
