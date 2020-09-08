#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
  char a[1000];
  while(1){
    fgets(a, 1000, stdin);
    //I used this hack https://www.maketecheasier.com/run-bash-commands-background-linux/
    for(int i = 0; i < 1000-3; ++i){
      if(a[i] == '\n'){
        a[i] = ' ';
        a[i+1] = '&';
        a[i+2] = '\0';
        break;
      }
    }
    // printf("%20s", a);
    system(a);
  }
}
// sample command(other types of loops don't work. maybe due to different syntax that supports terminal called by system)
// for i in $(seq 1 1 3); do echo Hello world; done