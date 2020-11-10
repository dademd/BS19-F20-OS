#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>


// program takes as arguments the names of input and output file

// assumes the following input structure in input.txt:
// line1: n(number of processes), m(number of resource types)
// next 1 line: E, vector
// next 1 line: V, vector of available resources
// next n lines: C, allocation matrix
// next n lines: R, request matrix

int main(int argc, char* argv[]) {
  FILE* in = fopen(argv[1], "r");
  FILE* out = fopen(argv[2], "w");

  int n, m;
  fscanf(in, "%d%d", &n, &m);
  
  int E[m];
  for(int i = 0; i < m; ++i){
    fscanf(in, "%d", &E[i]);
  }

  int A[m];
  for(int i = 0; i < m; ++i){
    fscanf(in, "%d", &A[i]);
  }

  int C[n][m];
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < m; ++j){
      fscanf(in, "%d", &C[i][j]);
    }
  } 

  int R[n][m];
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < m; ++j){
      fscanf(in, "%d", &R[i][j]);
    }
  }

  // fprintf(out, "[%d]", R[n-1][m-1]);
  
  // flags each for executed processes
  char marked[n];
  memset(marked, 0, sizeof(marked));
  
  // for(int i = 0; i < n; ++i) printf("%d", (int)marked[i]);

  // printf("%d", marked[0]);
  
  // number of found rows
  int found = 0;
  for(; found < n; ++found){
    // flag that any row is <= A
    char good = 0;
    
    // go row by row
    for(int i = 0; i < n && good == 0; ++i){
      // flag that current row is > A
      char bad = 0;

      if(marked[i] == 0){
        // check if it's less than or equal to A
        for(int j = 0; j < m; ++j){
          if(R[i][j] > A[j]){
            bad = 1;
          }
        }

        if(bad == 0){
          // found a <= row
          marked[i] = 1;
          good = 1;

          // printf("%d ", i);

          // free resources
          for(int j = 0; j < m; ++j){
              A[j] += C[i][j];
          }
        }
      }
    }

    // no <= row found
    if(good == 0){
      break;
    }
  }

  if(found == n){
    fprintf(out, "No deadlocks are found");
  }

  else{
    fprintf(out, "These processes are deadlocked:\n");
    for(int i = 0; i < n; ++i){
      if(marked[i] == 0){
        fprintf(out, "[ %d ]", i + 1);
      }
    }
  }
}