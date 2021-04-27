  
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <signal.h>

void kezeles();

void main() {
    printf("PID : %d\n",getpid());
    signal(SIGALRM, kezeles);
    pause();
    printf("kibillent\n");
    exit(0);
}

void kezeles() {
    printf("g616tl\n");
    
}