#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/riscv.h"
#include <stddef.h>

struct packet
{
    char name_1[25];
    char name_2[25];
    char name_3[25];
};

void *create_stack(int sz)
{
    return malloc(sz) + PGSIZE;
}

void print_st(void *arg)
{
    struct packet *data = (struct packet *)arg;
    printf("The kthreads library was written by %s, %s and %s.\n", data->name_1, data->name_2, data->name_3);
    exit(0);
}

int main(int argc, char *argv[])
{
    printf("----------STRUCT TEST----------\n");
    struct packet my_info = {
        .name_1 = "Agnay",
        .name_2 = "Richard",
        .name_3 = "Sean"};
    void *st_1 = create_stack(PGSIZE);

    printf("st_1 = %p \n", st_1);

    int tid_1 = kthread_create(print_st, (void *)&my_info, st_1);
    kthread_join(tid_1);

    exit(0);
}