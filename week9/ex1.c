#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char** argv){
  int frames = atoi(argv[1]);
  int ref_at_time = atoi(argv[2]);
  
  printf("/----\\\npage frames: %d\nreferences read at a tick: %d\n", frames, ref_at_time);
  
  int ftable[frames];
  int ages[frames];
  
  for(int i = 0; i < frames; ++i){
    ftable[i] = 0;
    ages[i] = 0;
  }

  int hit=0, miss=0;
  
  const int init_age = 1 << 7;
  
  // number of references read at a time <= frames
  
  while(1){
    for(int i = 0; i < frames; ++i){
      ages[i] >>= 1;
    }
    
    int eof = !EOF;

    
    for(int r = 0; r < ref_at_time; ++r){
      
      int ref;
      eof = scanf("%d", &ref);
      if(eof == EOF){
        break;
      }
      
      char found = 0;
      
      for(int j = 0; j < frames; ++j){
        if(ftable[j] == ref){
          ages[j] |= init_age;
          found = 1;
          hit++;
          break;
        }
      }
      
      if(!found){
        miss++;
        int pos = 0;
        int min_age = init_age;
        
        for(int j = 0; j < frames; ++j){
          if(ftable[j] == 0){
             pos = j;
             break;
          }
          if(ages[j] < min_age){
            pos = j;
            min_age = ages[j];
          }
        }
        
        ftable[pos] = ref;
        ages[pos] = init_age;
      }
    }
    
    if(eof == EOF){
      break;
    }
  }
  
  printf("\n");
  
  printf("hits: %d\nmisses:  %d\nhit / miss ratio: %f\n\\-----/\n\n", hit, miss, (hit * 1.) / miss);
}