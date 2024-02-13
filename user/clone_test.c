#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc, char *argv[]) {
    printf("---------[Clone Test Bed]---------\n\n");

    uint64 func = 0xdeadbeef;
    uint64 arg = 0x0baddeed;
    uint64 stack = 0xacacacac;
    
    int ret = clone((void(*)(void*)) func, (void*) arg, (void*) stack);  
    printf("return val = %d\n\n", ret);
    exit(0);
}


