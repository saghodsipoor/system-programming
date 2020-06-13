#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
	char *message;
	int n;
	pid_t pid;
	int exit_code;

	puts("fork starting...");
	switch (pid = fork())
	{
	case -1:
		message = "fork error\n";
		break;
	
	case 0:
		n = 5;
		message = "This is the child\n";
		exit_code = 37;
		break;

	default:
		n = 3;
		message = "This is the parent\n";
		exit_code = 0;
		break;
	}

	for (; n > 0; n--)
	{
		printf(message);
		sleep(1);
	}

	if (pid != 0) // if we are in parent
	{
		int stat_val;
		pid_t child_pid = wait(&stat_val);

		printf("Child has finished: PID = %d\n", child_pid);
		if (WIFEXITED(stat_val))
			printf("Child exited with code %d\n", WEXITSTATUS(stat_val));
		else
			printf("Child exited abnormally\n");
	}

	return exit_code;
}
