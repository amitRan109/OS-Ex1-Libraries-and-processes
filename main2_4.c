#define _GNU_SOURCE
#include<stdio.h>
#include<stdlib.h>
#include <sched.h>
#include<unistd.h>
char child_stack [10000+1];
int main1 (void *parm){ 
printf("\n\nmain2_1\nNumber of Id:  %d\n\n", getpid());
          	char * args[2] = {"./main2_1",NULL};
		execvp(args[0],args);

}
int main2 (void *parm){ 
printf("\n\nmain2_2\nNumber of Id:  %d\n\n", getpid());
          	char * args[2] = {"./main2_2",NULL};
		execvp(args[0],args);

}
int main3 (void *parm){ 
printf("\n\nmain2_3\nNumber of Id:  %d\n\n", getpid());
          	char * args[2] = {"./main2_3",NULL};
		execvp(args[0],args);

}

int main()
{
	int id1 = clone(main1, child_stack + 10000, CLONE_PARENT, 0);
        sleep(15);
	int id2 = clone(main2, child_stack + 10000, CLONE_PARENT, 0);
	sleep(15);
	int id3 = clone(main3, child_stack + 10000, CLONE_PARENT, 0);
    return 0;
} 
