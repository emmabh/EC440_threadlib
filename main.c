
#include <pthread.h>
#include <sys/time.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <setjmp.h>
#include "threads.h"
#include "ptr_mangle.h"


#define THREAD_CNT 10

void *count(void *arg){
  unsigned long int c = \
    (unsigned long int)arg;
  int i;
  for (i = 0; i < c; i++) {
    if ((i % 1000000) == 0) {
      printf("id: %x cntd to %d of %ld\n", \
      (unsigned int)pthread_self(), i, c);
    }
  }
  return arg;
}

int main(int argc, char **argv){
	pthread_t threads[THREAD_CNT];
    int i;

    //create THREAD_CNT threads
    for(i = 0; i<THREAD_CNT; i++) 
    {
        pthread_create(&threads[i], NULL, count, (void *)(10000000*(i+1)));
    }

    return 0;
}
