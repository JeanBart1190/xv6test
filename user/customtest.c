#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

/*
int main(int argc, char *argv[]){
    int pid = fork();
    if(pid > 0) {
        printf("parent: child=%d\n", pid);
        pid = wait((int *) 0);
        printf("child %d is done\n", pid);
    } else if(pid == 0) {
        printf("child: exiting\n");
        exit(0);
    } else {
        printf("fork error\n");
        exit(1);
    }
    exit(0);
}
*/

int p[2];
char *argv[2];
int main(int argc, char *argv[]){
    argv[0] = "wc";
    argv[1] = 0;
    pipe(p);
    if (fork() == 0) {
        printf("In child process\n\n");
        close(0);
        dup(p[0]);
        close(p[0]);
        close(p[1]);
        exec("/bin/wc", argv);
        exit(0);
    } else {
        printf("In parent process\n");
        close(p[0]);
        write(p[1], "hello world\n", 12);
        close(p[1]);
        wait((int *) 0);
    }
    exit(0);
}