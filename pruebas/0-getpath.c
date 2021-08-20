#include "../shell.h"
#include "../functions_02.c"
int main(void)
{
	char *copy_string = getpath();
	printf("%s\n\n", copy_string);
	if(copy_string)
	{
		free(copy_string);
	}
	return(0);
}
