  
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char const *argv[]) 
{
    int a = system("ls");
    
    if(WIFEXITED(a)) 
    {
        printf("Quit\n");
        printf(" %d\n", WEXITSTATUS(a));
    } 

    int b = system("lp");
    
    if(WIFEXITED(b)) 
    {
        printf("Quit\n");
        printf(" %d\n", WEXITSTATUS(b));
    }

    return 0;
}