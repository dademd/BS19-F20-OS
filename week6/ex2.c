#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

typedef struct event{int id, at, bt, ct, tat, wt;} event;

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
  printf("id: %d, at: %d, bt: %d\n", e.id, e.at, e.bt);
}

void scheduler(){
  

  // printf("Input number of processes: ");
  int n; scanf("%d", &n);
  
  // printf("For each of n processes, input Arrival Time and Burst Time for each process: ");
  event e[n];
  int completed[n];
  for(int i = 0; i < n; ++i) completed[i] = 0;
  
  for(int i = 0; i < n; ++i){
    e[i].id = i;
    scanf("%d %d", &(e[i].at), &(e[i].bt));
  }
  
  
  printf("\nStarting scheduling, time is 0\n");
  printf("%-4s %-4s %-4s %-4s %-7s %-6s\n", "Proc", "CT", "TAT", "WT", "Avg.TAT", "Avg.wt");
  
  qsort(e, n, sizeof(event), compare_events);
  
  int cur_time = e[0].at;
  double sum_tat = 0., sum_wt = 0.;
  
  // for(int i = 0; i < n; ++i){
  //   print_event(e[i]);
  // }
  // printf("cur: %d\n", cur_time);
  
  
  for(int i = 0; i < n;){
    // skip completed tasks
    if(completed[e[i].id] == 1) {i++; continue;}
    
    //choose temporary best event
    event *chosen = &e[i];
    // try to find the sleeping event with the least burst time
    for(int j = i; j < n; ++j){
      if(e[j].at > cur_time) break;
      
      if(completed[e[j].id] == 0 && e[j].bt < chosen->bt){
        chosen = &e[j];
      }
    }
    
    completed[chosen->id] = 1;
    
    // print_event(*chosen);
    // printf("id: %d, comp: %d\n", chosen->id, completed[chosen->id]);
    
    cur_time = max(cur_time, chosen->at);
    
    int ct = cur_time + chosen->bt;
    int tat = ct - chosen->at;
    int wt = tat - chosen->bt;
    
    sum_tat += tat;
    sum_wt += wt;
      
    printf("%-4d %-4d %-4d %-4d %-7.2f %-6.2f\n", chosen->id, ct, tat, wt, sum_tat / (i+1), sum_wt / (i+1));
    
    cur_time = ct;
    // sleep(1);
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
  fprintf(fp, "\nSJN\n");
  fclose(fp);
  
  printf("SJN\n");
  
  int tests;
  scanf("%d", &tests);
  
  for(int i = 0; i < tests; ++i){
    printf("Test %d\n", i);
    scheduler();
  }
}