#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/riscv.h"
#include <stddef.h>

void *create_stack(int sz)
{
    return malloc(sz) + PGSIZE;
}

void func(void *arg)
{
    sleep(10);
    printf("Should not be printing\n");
    exit(0);
}

int main(int argc, char *argv[])
{
    printf("----------STACKS TEST----------\n");
    void *st_1 = create_stack(PGSIZE);

    kthread_create(func, NULL, st_1);

    exit(0);
}