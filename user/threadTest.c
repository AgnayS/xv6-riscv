#include "kernel/param.h"
#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/fs.h"
#include "kernel/riscv.h"
#include "kernel/spinlock.h"
#include "kernel/proc.h"
#include "kernel/fcntl.h"
#include "kernel/syscall.h"
#include "kernel/memlayout.h"



void thread_function(void* arg) {
    printf("Hello from the thread! Arg: %d\n", *(int*)arg);
    exit(0);
}

int main() {
    int arg = 123;
    // void* stack = malloc(PGSIZE) + PGSIZE;

    // if (!stack) {
    //     printf("Failed to allocate stack for the thread\n");
    //     exit(1);
    // }

    int i;
    int tids[10];
    void* stacks[10];

    for (i = 0; i < 10; i++) {
      stacks[i] = malloc(PGSIZE) + PGSIZE;
    }

    for (i = 0; i < 10; i++)
    {
      tids[i] = kthread_create(thread_function, &arg, stacks[i]);
    }

    for (i = 0; i < 10; i++) {
      kthread_join(tids[i]);
    }

    printf("Thread finished execution\n");

    //free(stack);
    exit(0);
}




