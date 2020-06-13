#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
int main()
{
	char buff[1024];
	int in, out;
	int nread;

	in = open("file.in", O_RDONLY);
	out = open("file.out", O_WRONLY|O_CREAT, S_IRUSR|S_IWUSR);

	while((nread = read(in, buff, 1024)) > 0)
		write(out, buff, nread);
	
		
	exit(0);
}
