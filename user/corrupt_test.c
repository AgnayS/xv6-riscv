#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/riscv.h"
#include <stddef.h>

#define START_NUM 10

int num = START_NUM;

void *create_stack(int sz)
{
    return malloc(sz) + PGSIZE;
}

void func_1(void *arg)
{
    num++;
    exit(0);
}

void func_2(void *arg)
{
    printf("num = %d expected  %d\n", num, START_NUM + 1);
    exit(0);
}

int main(int argc, char *argv[])
{
    printf("----------CORRUPT MEM AFTER THREAD DIES TEST----------\n");
    void *st_1 = create_stack(PGSIZE);
    void *st_2 = create_stack(PGSIZE);

    int tid_1 = kthread_create(func_1, NULL, st_1);
    kthread_join(tid_1);
    free(st_1 - PGSIZE);

    int tid_2 = kthread_create(func_2, NULL, st_2);
    kthread_join(tid_2);
    free(st_2 - PGSIZE);

    exit(0);
}