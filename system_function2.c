#include <stdlib.h>
#include <stdio.h>

int main()
{

	printf("Running ps\n");
	system("ps ax &");
	printf("Done\n");

	return 0;
}
