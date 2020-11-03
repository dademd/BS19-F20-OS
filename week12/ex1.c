#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
  system("echo $(cat /dev/urandom | tr -dc 'a-zA-Z0-9' | fold -w $(( 20 )) | head -n 1) > ex1.txt");
}