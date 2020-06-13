#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
	char *message;
	int n;
	pid_t pid;

	switch (pid = fork())
	{
	case -1:
		message = "fork error\n";
		break;
	
	case 0:
		n = 5;
		message = "I'm child process with PID: %d\n";
		break;

	default:
		n = 3;
		message = "I'm parent process with PID: %d\n";
		break;
	}

	pid = getpid();
	for (; n > 0; n--)
	{
		printf(message, pid);
		sleep(1);
	}

	return 0;
}
