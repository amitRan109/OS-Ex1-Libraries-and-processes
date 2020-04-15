#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <syslog.h>


int main()
{
    // create child thay will be deamon
    pid_t pid = fork();

    if (pid == 0)
    {
        //we are in child

        //move to root dir, used to not block the file system
        chdir("/");

        //move the child to another session, so the parent may be closed
        setsid();

        printf("daemon start\n");

        //close=ing output channels
        close(stdout);
        close(stdin);
        close(stderr);

        //log open
        openlog("myDaemon", LOG_PID, LOG_DAEMON);
        syslog(LOG_NOTICE, "start daemon");
        usleep(3000000);
        syslog(LOG_NOTICE, "doing some work...");
        usleep(3000000);
        syslog(LOG_NOTICE, "daemon done");
    }
    else
    {
        printf("daemon PID %d\n" , pid);
    }
    return 0;
}