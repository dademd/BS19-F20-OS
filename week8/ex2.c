#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

int main(){
  size_t chunk = 10*(1<<20);
  for(int i = 0; i < 10; ++i){
    int* p = malloc(chunk);
    memset(p,0,chunk);
    sleep(1);
  }
}