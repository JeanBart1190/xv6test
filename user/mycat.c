#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

char buf[512];
int main(int argc, char *argv[]){
    int n;
    n = read(0, buf, sizeof buf);
    if(n == 0){
        exit(0);
    }
    if(n < 0){
        fprintf(2, "read error\n");
        exit(1);
    } 
    if(write(1, buf, n) != n){
        fprintf(2, "write error");
        exit(1);
    }
    exit(0);
}