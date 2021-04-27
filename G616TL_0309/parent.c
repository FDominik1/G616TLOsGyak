
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char const *argv[]) 
{
    pid_t pid;
    int s;

    if((pid = fork()) < 0) 
    {
        perror("process error");
    } 
    else if(pid == 0) 
    {
        if((execl("./child","child", (char *)NULL)) < 0) 
        {
            perror("excel error");
        }
    }
	
    if(waitpid(pid, &s, 0) < 0) 
    {
        perror("wait error");
    }

    return 0;
}