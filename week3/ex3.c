#include <stdio.h>
#include <malloc.h>

struct node{
    int val;
    struct node* next;
};

struct list{
    struct node* head;
    struct node* tail;
};

void print_list(struct list l){
    printf("[");
    struct node* cur = l.head->next;
    while (cur != l.tail){
        printf("%d, ", cur->val);
        cur = cur->next;
    }
    printf("]\n");
}

// no checks for out of bound
void insert_node(int idx, int val, struct list l){
    struct node* cur = l.head;
    for(int i = 0; i < idx; ++i){
        cur = cur->next;
    }
    struct node* new = malloc(sizeof(struct node));
    new->next = cur->next;
    cur->next = new;
    new->val = val;
}

void delete_node(int idx, struct list l){
    struct node* cur = l.head;
    for(int i = 0; i < idx; ++i){
        cur = cur->next;
    }
    struct node* deleted = cur->next;
    cur->next = (cur->next)->next;
    free(deleted);
}

int main(){
     struct list l;
     l.head->next = l.tail;

     insert_node(0,1,l);
     print_list(l);
     insert_node(0,2,l);
     print_list(l);
     insert_node(2,4,l);
     print_list(l);
     delete_node(0, l);
     print_list(l);
     delete_node(1, l);
     print_list(l);
     delete_node(0, l);
     print_list(l);
}