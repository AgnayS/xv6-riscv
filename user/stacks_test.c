#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/riscv.h"
#include <stddef.h>

void* create_stack(int sz) {
  return malloc(sz) + PGSIZE;
}


void print_st(void* arg) {
  sleep(3);
  int var = 4;
  int* id = (int*)arg;
  printf("Addr of int on thread %d stack = %p\n", *id ,&var);
  exit(0);
}

int main(int argc, char* argv[]) {
  printf("----------STACKS TEST----------\n");
  int t1 = 1;
  int t2 = 2; 
  void* st_1 = create_stack(PGSIZE);
  void* st_2 = create_stack(PGSIZE);

  printf("st_1 = %p  st_2 = %p\n", st_1, st_2);

  int tid_1 = kthread_create(print_st, (void*)&t1, st_1);
  kthread_join(tid_1);

  int tid_2 = kthread_create(print_st, (void*)&t2, st_2);
  kthread_join(tid_2);

  exit(0);
}
