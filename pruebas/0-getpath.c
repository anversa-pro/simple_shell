#include "../shell.h"
#include "../strtok.c"
int main(void)
{
	char *copy_string = getpath();
	printf("%s\n", copy_string);
	if(copy_string)
	{
		free(copy_string);
	}
	return(0);
}
