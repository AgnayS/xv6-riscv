#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc, char *argv[]) {
    printf("----------[Join Test Bed]---------\n\n");

    uint64 stack = 0xffffffff;
    int ret = join((void**) stack);
    printf("return val = %d\n\n", ret);
    exit(0);
}
