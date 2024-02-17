#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/riscv.h"
#include <stddef.h>

void* create_stack(int sz) {
  return malloc(sz) + PGSIZE;
}


void print_st(void* arg) {
  int* num = (int*) arg;
  printf("My favorite class is csse%d\n", *num);
  exit(0);
}

int main(int argc, char* argv[]) {
  printf("----------ACCESS ARGS TEST----------\n");
  int t1 = 332;
  void* st_1 = create_stack(PGSIZE);

  int tid_1 = kthread_create(print_st, (void*)&t1, st_1);
  kthread_join(tid_1);


  exit(0);
}
