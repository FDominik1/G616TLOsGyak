  
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <signal.h>
#include <stdbool.h>
#include <stdlib.h>

void Kezelo() ;

void main(int argc, char const *argv[]) {
    if (argc < 1) {
        perror("nincs argumentum");
        exit(-1);
    }
    int n = atoi(argv[1]);  
    signal(SIGTERM, Kezelo);
    while (true) {
        printf("%d\n", n);
        sleep(3);
    }
}

void Kezelo() {
    signal(SIGTERM, SIG_IGN);
}