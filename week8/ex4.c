#include <stdlib.h>
#include <sys/resource.h>
#include <stdio.h>
#include <sys/time.h>
#include <string.h>
#include <unistd.h>

int main(){
  size_t chunk = 10*(1<<20);
  for(int i = 0; i < 10; ++i){
    int* p = malloc(chunk);
    memset(p,0,chunk);
    
    struct rusage* rus;
    getrusage(RUSAGE_SELF, rus);
    long r = rus->ru_maxrss;
  
    printf("Shared mem usage: %ld\n", r);
    sleep(1);
  }
}