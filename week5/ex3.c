#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define NULL_PTHREAD 0
#define MAX_buff 1000000

// P puts objects here, C takes
int buff=0;

int P_enabled=1;
int C_enabled=0;

pthread_t thread_P,thread_C;

void* P(void *argument){
	int i=0;
	while(1){
	 // block until buff is not full
		while(buff == MAX_buff);
		if(i%1000 == 0)
			// print id of product and buff size
			printf("P %d %d\n",i,buff);
		if(buff < MAX_buff){//Make product
			buff++;
			i++;
		}
	}
}

void* C(void *argument){
	int i=0;
	while(1){
		//While buff not empty
		while(buff==0);
		if(i%1000==0)
			// print id of pulled product and buff size
			printf("C %d %d\n",i,buff);
		// pull product
		if(buff>0){
			i++;
			buff--;
		}
	}
}



int main(){
	pthread_create(&thread_P,NULL,&P,NULL);
	pthread_create(&thread_C,NULL,&C,NULL);
	pthread_join(thread_P,NULL);
	return 0;
}
