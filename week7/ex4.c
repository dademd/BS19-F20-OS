#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

void *my_realloc(void *ptr, size_t size){
  if(ptr == NULL) return malloc(size);
  void *newptr;
  int msize;
  msize = ((size_t*)ptr)[-1];
  if (size <= msize)
      return ptr;
  newptr = malloc(size);
  memcpy(newptr, ptr, msize);
  free(ptr);
  return newptr;
}

int main(){
	//Allows you to generate random number
	srand(time(NULL));

	// Allows user to specify the original array size, stored in variable n1.
	printf("Enter original a1 size:");
	int n1=0;
	scanf("%d",&n1);

	//Create a new array of n1 ints
	int* a1 = malloc(n1*sizeof(int));
	int i;
	for(i=0; i<n1; i++){
		//Set each value in a1 to 100
		a1[i]=100;
		
		//Print each element out (to make sure things look right)
		printf("%d ", a1[i]);
	}

	//User specifies the new array size, stored in variable n2.
	printf("\nEnter new array size: ");
	int n2=0;
	scanf("%d",&n2);

	//Dynamically change the array to size n2
	a1 = my_realloc(a1, n2*sizeof(int));

	//want to use uninitialized variables.

// 	for(int j = n1; j < n2; ++j){
// 	  a1[j] = 0;
// 	}
	

	for(i=0; i<n2;i++){
		//Print each element out (to make sure things look right)
		printf("%d ",a1[i]);
	}
	printf("\n");
	
	//Done with array now, done with program :D
	
	return 0;
}
