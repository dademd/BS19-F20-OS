#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void *t_func(void* arg){
  printf("I was created on i = %d. Actually, my id is %lu\n",  *((int *)arg), pthread_self());
  
  return NULL;
}

int main(){
  const int THREADS = 6;
  pthread_t t_id;
  
  for(int i = 0; i < THREADS; ++i){
    printf("I'm creating my thread %d\n", i);
    pthread_create(&t_id, NULL, t_func, &i);
  
    printf("I created thread %d\n", i);
  }
  sleep(1);
}

// Although the threads were "created", they remained blocked for some time
// That is why some messages from them come after main says it has created the threads
// You probably can see that some of them were created even after i became 6