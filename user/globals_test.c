#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/riscv.h"
#include <stddef.h>

#define NUM_THREADS   14 // this is the max num of threads we can have without needing to allocate another page table

int num_spawned = 0;

void* create_stack(int sz) {
  return malloc(sz) + PGSIZE;
}


void increment(void* arg) {
  num_spawned++;  
  exit(0);
}

int main(int argc, char* argv[]) {
  printf("----------GLOBALS TEST----------\n");
  
  int i = 0;
  int tids[NUM_THREADS];
  void* stacks[NUM_THREADS];

  for (i = 0; i < NUM_THREADS; i++)
  {
    stacks[i] = create_stack(PGSIZE);
    tids[i] = kthread_create(increment, NULL, (void*)stacks[i]);
  }

  for (i = 0; i < NUM_THREADS; i++) {
    kthread_join(tids[i]);
  }

  printf("Final val of num_spawned = %d and expected is %d\n", num_spawned, NUM_THREADS);
  exit(0);
}
