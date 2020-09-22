#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

typedef struct event{int id; double at, bt, remainig_time, ct, tat, wt;} event;

int compare_events(const void* a, const void* b)
{
    event arg1 = *(const event*)a;
    event arg2 = *(const event*)b;
    int comp_by_at = (arg1.at > arg2.at) - (arg1.at < arg2.at);
    return (comp_by_at != 0 ? comp_by_at : ((arg1.bt > arg2.bt) - (arg1.bt < arg2.bt)));
}

#define min(X, Y) (((X) < (Y)) ? (X) : (Y))
#define max(X, Y) (((X) > (Y)) ? (X) : (Y))

void print_event(event e){
  printf("id: %d, at: %lf, bt: %lf\n", e.id, e.at, e.bt);
}

void scheduler(){
  

  // printf("Input number of processes: ");
  int n; scanf("%d", &n);
  
  double quantum; scanf("%lf", &quantum);
  
  // printf("For each of n processes, input Arrival Time and Burst Time for each process: ");
  event e[n];
  int completed[n];
  for(int i = 0; i < n; ++i) completed[i] = 0;
  
  for(int i = 0; i < n; ++i){
    e[i].id = i;
    scanf("%lf %lf", &(e[i].at), &(e[i].bt));
    e[i].remainig_time = e[i].bt;
  }
  
  
  printf("\nQuantum is: %lf\nStarting scheduling, time is 0\n", quantum);
  printf("%-4s %-4s %-4s %-4s %-7s %-6s\n", "Proc", "CT", "TAT", "WT", "Avg.TAT", "Avg.wt");
  
  qsort(e, n, sizeof(event), compare_events);
  
  double cur_time = e[0].at;
  double sum_tat = 0., sum_wt = 0.;
  
  // for(int i = 0; i < n; ++i){
  //   print_event(e[i]);
  // }
  // printf("cur: %d\n", cur_time)
  
  int pending = n;
  
  for(int i = 0; pending > 0 && i < n; i = (i+1) % n){
    // skip completed tasks
    if(completed[i] == 1) continue;
    
    cur_time = max(cur_time, e[i].at);
    
    if(e[i].remainig_time <= quantum){
      pending--;
      completed[i] = 1;
      printf("finished P%d\n", e[i].id);  
      int ct = cur_time + e[i].remainig_time;
      int tat = ct - e[i].at;
      int wt = tat - e[i].bt;
      
      sum_tat += tat;
      sum_wt += wt;
        
      printf("%-4d %-4d %-4d %-4d %-7.2f %-6.2f\n", e[i].id, ct, tat, wt, sum_tat / (i+1), sum_wt / (i+1));
      cur_time = ct; 
      continue;
    }
    printf("P%d=\n", e[i].id);
    e[i].remainig_time -= quantum;
    cur_time += quantum;
    // sleep(1);
  }
  
  printf("Scheduled!\n\n\n");
  
  FILE *fp;
  fp = fopen("results.txt","a+");
  fprintf(fp, "%-7.2lf %-6.2lf\n", sum_tat/n, sum_wt/n);
  fclose(fp);
}

int main(){
  //new algorithm
  FILE *fp;
  fp = fopen("results.txt","a+");
  fprintf(fp, "\nRound Robin\n");
  fclose(fp);
  
  printf("Round Robin\n");
  
  int tests;
  scanf("%d", &tests);
  for(int i = 0; i < tests; ++i){
    printf("Test %d\n", i);
    scheduler();
  }
}