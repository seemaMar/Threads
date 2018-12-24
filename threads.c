
#include <stdio.h>
#include <pthread.h>
#include <sys/time.h>

long counter = 0;

void *theThread(void *);


int main(void) {
  pthread_t posixThreadId;
  int result;
  int threadExitStatus;
  void *pThreadExitStatus = &threadExitStatus;
  

  //create and start the new thread
  result = pthread_create(&posixThreadId, NULL, theThread, NULL);
  counter++;
  
  result = pthread_join(posixThreadId, pThreadExitStatus);
  //if (result==0) printf("pthread_join not failed, error=%d\n",result);
  printf("Counter = %d\n", counter);
  
  return 0;
}

/**
 ** This is where the thread 2 starts executing
 */
void *theThread(void *arg) {

  //Print a bunch of stuff to stdout
  //printStuff("thread",1000);
  counter--;
  pthread_exit((void *) 0);
}
