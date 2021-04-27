#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

int main() {
    int n;
    pid_t childpid;
    char string[] = "XY G616TL\n";
    char read[80];
    int fd[1];
    pipe(fd);
    
    if((childpid = fork()) == -1) {
        perror("fork");
        exit(1);
    }

    if(childpid == 0) {
        close(fd[0]);
        write(fd[1], string, (strlen(string)+1));
        exit(0);
    } else {      
        close(fd[1]);
        n = read(fd[0], read, sizeof(read));
        printf("kapott string: %s", read);
    }
    
    return(0);
}