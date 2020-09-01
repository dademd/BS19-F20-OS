#include <stdio.h>

void bubble_sort(int a[], int n){
    for(int i = 0; i < n; ++i){
        for(int j = i; j+1 < n; ++j){
            if(a[j] > a[j+1]){
                int t = a[j+1];
                a[j+1] = a[j];
                a[j] = t;
            }
        }
    }
}

int main(){
    int n; scanf("%d", &n);
    int a[n];
    for(int i = 0; i < n; ++i){
        scanf("%d", &a[i]);
    }

    bubble_sort(a, n);

    for(int i = 0; i < n; ++i){
        printf("%d ", a[i]);
    }
}