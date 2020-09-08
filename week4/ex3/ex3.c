#include <stdio.h>
#include <stdlib.h>
int main(){
  char a[1000];
  while(1){
    fgets(a, 1000, stdin);
    system(a);
  }
}