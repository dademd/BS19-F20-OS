#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main(void) {
  char* src_path = "ex1.txt";
  int src = open(src_path, O_RDONLY);
  
  struct stat src_stat = {};
  stat(src_path, &src_stat);

  size_t src_size = src_stat.st_size;

  char *src_map = mmap(NULL, src_size, PROT_READ,MAP_SHARED, src, 0);

  char* dest_path = "ex1.memcpy.txt";
  int dest = open(dest_path, O_RDWR | O_CREAT);
  lseek(dest, src_size-1, SEEK_SET);
  write(dest, "", 1);
  char *dest_map = mmap(NULL, src_size, PROT_READ | PROT_WRITE, MAP_SHARED, dest, 0);

  memcpy(dest_map, src_map, src_size);
  
  msync(dest_map, src_size, MS_SYNC);

  return 0;
}