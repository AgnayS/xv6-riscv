#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/riscv.h"


int* np_var;

void add_mem(void* arg){
  np_var = (int*)sbrk(4);
  *np_var = 404;
  printf("set value successfully...\n");
  exit(0);
}

void thread_sleep(void* arg) {
  sleep(10);
  printf("The value in the new mem is: %d\n", *np_var);
  exit(0);
}

void* create_stack(int sz) {
  return malloc(sz) + PGSIZE;
}


int main(int argc, char *argv[]) {
    printf("----------MEM TEST----------\n");
    void* sleep_sp = create_stack(PGSIZE);
    void* mem_sp = create_stack(PGSIZE);

    int sleep_tid = kthread_create(thread_sleep, 0, sleep_sp);
    int mem_tid = kthread_create(add_mem, 0, mem_sp);

    kthread_join(sleep_tid);
    kthread_join(mem_tid);

    exit(0);
}
