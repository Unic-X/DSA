#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct node{
    int data;
    struct node * next;
}node;


int size = 4;

node * insertF(node * a,int val){
    struct node* temp;
    temp = (node*)malloc(sizeof(*temp));
    if(temp==NULL){
    printf("Cannot allocate mem");
    exit(-1);
    
    }
        if (a == NULL) {
        temp->data = val;
        temp->next = temp;
        a = temp;
        return a;
    }
    
    
    temp->data = val;
    temp->next = a;
    return temp;
    
}


node * insert(node * a,int val){
    struct node* temp;
    temp = (node*)malloc(sizeof(*temp));
    if(temp==NULL){
    printf("Cannot allocate mem");
    exit(-1);
    
    }
        if (a == NULL) {
        temp->data = val;
        temp->next = temp;
        a = temp;
        return a;
    }
    
    node * curr = a->next;

    while (curr->next!=a)
    {
        curr=curr->next;
    }
    temp->data = val;
    curr->next=temp;

    temp->next=a;

    return a;
    
}

void display(node * list){
    if (list ==NULL)
    {
        printf("GAlat");
        return;
    }

    node * curr = list;
    do
    {
        printf("%d \n",curr->data);
        curr = curr->next;
    } while (curr!=list);
    
    
    
    
    
}




int main()
{
    node * list = NULL;
    list = insert(list,5);


    clock_t t;
    t = clock();

    for (int i = 0; i < 200000; i++)
    {
        list = insertF(list,i);
    }
    
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds

    printf("took %f seconds to execute \n", time_taken);


    free(list);

}
