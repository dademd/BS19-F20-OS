#include <stdio.h>
void swp(int *pa, int *pb){
    int c;
    c = *pb;
    *pb = *pa;
    *pa = c;
}
int main() {   
    int a, b;
    printf("Input 2 integers: ");
    scanf("%d %d", &a, &b);
    int *pa = &a, *pb = &b;
    swp(pa,pb);
    printf("%d %d", a, b);
    return 0;
}