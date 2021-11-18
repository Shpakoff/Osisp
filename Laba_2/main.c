#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stdio.h>

int fatal(char *s)
{
   perror(s);
   exit (1);
}


void main()
{
    //char command[100];    
    //fgets(command,sizeof command, stdin);
    //char * const av[]={command, (char *)0};
    pid_t pid;
    switch (pid = fork()) {
        case -1:
            fatal("Ошибка вызова fork");
        break;
        case 0:
            /* Потомок вызывает exec */
            execl("/bin/bash","bash","-c","ls",(char *)0);
            fatal("Ошибка вызова exec");
        break;
        default:
            /* Родительский процесс вызывает wait для приостановки */
            /* работы до завершения дочернего процесса. */
            wait ( (int *)0);
            printf ("Программа ls завершилась\n");
            exit (0);
    }
}