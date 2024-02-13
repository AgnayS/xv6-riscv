#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

void increment(void *);

int main(int argc, char *argv[]) {
    printf("---------[Clone Test Bed]---------\n\n");
    
    int num = 9;
    int* arg = &num;
    int** stack = &arg;
    
    int ret = clone(increment, (void*) arg, (void*) stack);  
    printf("return val = %d\n\n", ret);
    exit(0);
}


void increment(void* arg) {
  printf("Hello from increment function");
  int* num = (int*) arg;
  *num += 1;
}


