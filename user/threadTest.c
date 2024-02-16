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
    int arg2 = 456;
    void* stack = malloc(PGSIZE) + PGSIZE;
    void* stack2 = malloc(PGSIZE) + PGSIZE;
    if (!stack) {
        printf("Failed to allocate stack for the thread\n");
        exit(1);
    }
    if (!stack2){
        printf("Failed to allocate stack for the thread\n");
	exit(1);
    }

    kthread_create(thread_function, &arg, stack);
    kthread_join(0);
    kthread_create(thread_function, &arg2, stack2);
    kthread_join(0);

    printf("Threads finished execution\n");

    free(stack);
    free(stack2);
    exit(0);
}





