#include <stdio.h>
#include <string.h>

int main(void) {
  printf("Input the string: ");
  const char str[1000];
  fgets(str, sizeof(str),stdin);
  int t = strlen(str);
  for(int i = t-1; i >= 0; --i){
    printf("%c", str[i]);
  }
  printf("\n");
}