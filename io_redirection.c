/*
possible use:
type "./io_redirection < FILE_NAME" in shell
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
	char line[200];
	while (fgets(line, 200, stdin) != NULL)
		fputs(line, stdout);

	return 0;
}
