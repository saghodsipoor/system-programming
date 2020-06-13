#include <unistd.h>
#include <stdlib.h>

int main()
{
	if (write(STDOUT_FILENO, "here is some data\n", 18) != 18)
		write(STDERR_FILENO, "A write error has occurred\n", 27);	
	
	return 0;
};
