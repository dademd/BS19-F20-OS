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
    pthread_join(t_id, NULL);
    printf("I created thread %d\n", i);
  }
}