#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"


int main(int argc, char*argv[]){
    if(argc < 2){
        printf("Error: sleep <ticks>\n");
        exit(0);
    }
    int ticks = atoi(argv[1]);
    if(sleep(ticks)!=0){
        printf("Error in sleep sys_call!\n");
    }
    exit(0);
}