#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

void print(const char *text){
        int i;
        for ( i = 0; i < 20; i++)
        {
            printf("Hello from %s\n" ,text);
            usleep(1000000);
        }
        
}
int main()
{
    //create child
    pid_t pid = fork();
    if (pid==0){
        //we are in child

        //create a grand child
        pid_t pid = fork();

        if(pid==0){
            //we are in grand child
            print("grand child\n");
        }
        else{
            print("child\n");
        }
    }
    else{
        print("parent\n");
    }
    return 0;
}