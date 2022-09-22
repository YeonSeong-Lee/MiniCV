#include <stdio.h>
#include <stdlib.h>

void	safe_open(char *path, FILE **fp)
{
	*fp = fopen(path, "r");
	if (!fp)
	{
		printf("file no open");
		exit(1);
	}
}