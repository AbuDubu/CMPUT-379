#include <stdio.h>     // printf, perror
#include <stdlib.h>    // exit, malloc, free
#include <unistd.h>    // fork, getpid, getppid, getcwd, sleep, exec*
#include <sys/types.h> // pid_t
#include <sys/wait.h>  // wait, waitpid

int main()
{
    char buff[1024];
    printf("CURRENT (%d) PARENT (%d)\n", getpid(), getppid());
    getcwd(buff, sizeof(buff));
    printf("Current Directory: %s\n", buff);

    int child = fork();

    if (child == 0)
    {
        printf("CHILD (%d) PARENT (%d)\n", getpid(), getppid());
        getcwd(buff, sizeof(buff));
        printf("CHILD Current Directory: %s\n", buff);

        sleep(2);
    }
    else
    {
        printf("CURRENT (%d) PARENT (%d)\n", getpid(), getppid());
        getcwd(buff, sizeof(buff));
        printf("Current Directory: %s\n", buff);

        wait(NULL);
    }
    if (child == 0)
    {
        printf("CHILD Finnished...\n");
    }
    else
    {
        printf("Parent Finished...\n");
    }

    return 0;
}