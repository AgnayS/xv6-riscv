#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/riscv.h"

void *create_stack(int sz)
{
    return malloc(sz) + PGSIZE;
}

int main(int argc, char *argv[])
{
    printf("----------STACKS TEST----------\n");

    exit(0);
}