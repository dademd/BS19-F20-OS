#include<stdio.h>
#include<stdlib.h>

typedef struct event{int id, at, bt, ct, tat, wt;} event;

int compare_events(const void* a, const void* b)
{
    event arg1 = *(const event*)a;
    event arg2 = *(const event*)b;
    return (arg1.at > arg2.at) - (arg1.at < arg2.at);
}

#define min(X, Y) (((X) < (Y)) ? (X) : (Y))
#define max(X, Y) (((X) > (Y)) ? (X) : (Y))

void scheduler(){
  

  // printf("Input number of processes: ");
  int n; scanf("%d", &n);
  
  // printf("For each of n processes, input Arrival Time and Burst Time for each process: ");
  event e[n];
  for(int i = 0; i < n; ++i){
    e[i].id = i;
    scanf("%d %d", &(e[i].at), &(e[i].bt));
  }
  
  qsort(e, n, sizeof(event), compare_events);
  
  printf("\nStarting processing, time is 0\n");
  printf("%-4s %-4s %-4s %-4s %-7s %-6s\n", "Proc", "CT", "TAT", "WT", "Avg.TAT", "Avg.WT");
  
  int cur_time = e[0].at;
  double sum_tat = 0., sum_wt = 0.;
  
  for(int i = 0; i < n; ++i){
    cur_time = max(cur_time, e[i].at);
    
    int ct = cur_time + e[i].bt;
    int tat = ct - e[i].at;
    int wt = tat - e[i].bt;
    
    sum_tat += tat;
    sum_wt += wt;
      
    printf("%-4d %-4d %-4d %-4d %-7.2f %-6.2f\n", e[i].id, ct, tat, wt, sum_tat / (i+1), sum_wt / (i+1));
    
    cur_time = ct;
  }
  
  printf("Scheduled!\n\n\n");
  
  FILE *fp;
  fp = fopen("results.txt","a+");
  fprintf(fp, "%-7.2lf %-6.2lf\n", sum_tat/n, sum_wt/n);
  fclose(fp);
}

int main(){
  FILE *fp;
  fp = fopen("results.txt","a+");
  fprintf(fp, "\nFCFS\n");
  fclose(fp);
  
  printf("FCFS\n");
  
  int tests;
  scanf("%d", &tests);
  
  for(int i = 0; i < tests; ++i){
    printf("Test %d\n", i);
    scheduler();
  }
}