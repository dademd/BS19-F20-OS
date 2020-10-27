#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>
#include <stdio.h>

int main(){
  setvbuf(stdout, NULL, _IOLBF, 0);

  char c[] = "Hello";
  for(int i = 0; i < strlen(c); ++i){
    printf("%c", c[i]);
    sleep(1);
  }

  printf("\n");
}