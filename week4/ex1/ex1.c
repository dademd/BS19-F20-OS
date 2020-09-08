#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
int main(){
  int n = fork();
  printf(n ? "Hello from parent [PID - %d]\n" : "Hello from child [PID - %d]\n", n);
}