#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>
#include <sys/stat.h>

int main(void) {
  char* dest_path = "ex1.txt";
  int dest = open(dest_path, O_RDWR | O_CREAT);
  
  const char *text = "This is a nice day!";
  size_t text_size = strlen(text);
  lseek(dest, text_size, SEEK_SET);
  write(dest, "", 1);

  char *map = mmap(NULL, text_size, PROT_READ | PROT_WRITE, MAP_SHARED, dest, 0);
  
  ftruncate(dest, text_size);
  memcpy(map, text, text_size);

  return 0;
}