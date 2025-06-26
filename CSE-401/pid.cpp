#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>


int main()
{
    printf("My process ID is : %d\n",getpid());

    pid_t parent_pid;
    parent_pid=getppid();
    printf("My parent's process ID is : %d\n", parent_pid);
    exit(0);
}
