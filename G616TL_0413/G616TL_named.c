#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define N 128

int main()
{

	char b[N];
	int pid, fajl;
	char input[] = "Földesi Dominik";
	char * fifo = "/users/g616tl";

	mkfifo(fifo, 0666);

	pid = fork();

	if (pid < 0)
	{
		exit(2);
	}

	if (pid == 0)
	{
		fajl = open(fifo, O_WRONLY);
		write(fajl, input, strlen(input)+1);
	}

	else if (pid > 0 )
	{
		fajl = open(fifo, O_RDONLY);
		read(fajl, b, strlen(input)+1);
		close(fileDesc);
	}

	return 0;
}