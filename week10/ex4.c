#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
  char dir[] = "tmp";
  DIR *dirp = opendir(dir); 
  struct dirent* dp;
  
  while ((dp = readdir(dirp)) != NULL) {
    char fpath[300];
    sprintf(fpath, "%s/%s", dir, dp->d_name);
    
    struct stat fstat;
    stat(fpath, &fstat);
    
    if(fstat.st_nlink >= 2){
      
      char command[100];
      sprintf(command, "echo inode: %ld {; find . -inum %ld; echo }", dp->d_ino, dp->d_ino);
      
      system(command);
    }
  }
}