#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"


int main(int argc, char *argv[]) {
    int p[2];
    char byte = 'x';
    pipe(p);

    int pid = fork();
    if(pid > 0){
        char buf[256];
        //父进程
        printf("is parent \n") ;
        write(p[1], &byte, 1);
        sleep(1);
        close(p[1]);
        if(read(p[0], buf, 1)){
            printf("%d: received pong\n", getpid());
        }

        exit(0);
    }else if (pid == 0){
        char buf[256];
        //子进程
        printf("is child \n");
        if(read(p[0], buf, 1)){
            printf("%d: received ping\n", getpid());
        }
        sleep(1);
        close(p[0]);
        write(p[1], &byte, 1);

        exit(0);
    }else{
        printf("fork error \n");
        exit(1);
    }
}
