#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]){
  int max_len = 1000;
  char str[max_len];
  while(fgets(str, max_len, stdin)){
    int len = strlen(str);
    fwrite(str, sizeof(char), max_len, stdout);
    
    for(int i = 3; i < argc; ++i){
      FILE* f = fopen(argv[i], "a+");
      fwrite(str, sizeof(char), len, f);
    }
  }
}