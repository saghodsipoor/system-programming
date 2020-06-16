#include <stdlib.h>
#include <stdio.h>

#include <signal.h>
#include <sys/types.h>
#include <unistd.h>

static int alarm_fired = 0;

void ding(int sig)
{
	alarm_fired = 1;
}

int main(int argc, char *argv[])
{
	printf("alarm program started\n");
	pid_t pid = fork();

	switch (pid)
	{
	case -1:
		perror("fork error: child process wasn't created.\n");
		exit(1);
	
	case 0:
		printf("waiting for 5 seconds\n");
		sleep(5);
		kill(getppid(), SIGALRM);
		exit(0);

	default:
		break;
	}

	(void) signal(SIGALRM, ding);
	
	printf("waiting for child signal\n");
	pause();

	// if SIGALRM is received
	if (alarm_fired)
		printf("DING!\n");
	
	return 0;
}
