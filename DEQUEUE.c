#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>

typedef struct CQUEUE
{
    int * values;
    int head,tail,size;
}queue;

queue * queueInit(queue* q,int max_size){
    q->head = 0;
    q->size = max_size;
    q->tail = -1;
    q->values = malloc(sizeof(int)*max_size);
    return q;
}

bool isQEmpty(queue * q){
    return (q->head > q->tail);
}

bool isLQFull(queue * q){
    return(q->head == 0);
}

bool isRQFull(queue * q){
    return(q->tail == q->size-1);
}


void Lenqueue(queue * q,int value){
    if (isLQFull(q))
    {
        printf("A");
        return;
    }
    
    q->head--;
    q->values[q->head] = value;

}


void Renqueue(queue * q,int value){
    if (isRQFull(q))
    {
        printf("B");
        return;
    }
    
    q->tail++;
    q->values[q->tail] = value;
    
}


void Rdeque(queue * q){
    if (isQEmpty(q))
    {
        printf("C");
        return;
    }
    
    q->tail--;
    
}

void Ldeque(queue * q){
    if (isQEmpty(q))
    {
        printf("D");
        return;
    }
    
    q->head++;
    
}


void display(queue * q){
    int curr = q->head;

    while (curr<=q->tail)
    {
        printf("%d->",q->values[curr]);
        curr++;
    }
    printf("\n");
    

}


int main(int argc, char const *argv[])
{
    queue q;

    queueInit(&q,6);

    Renqueue(&q,5);
    Renqueue(&q,4);
    Renqueue(&q,3);
    Renqueue(&q,2);
    Renqueue(&q,1);
    Renqueue(&q,-1);

    display(&q);

    Rdeque(&q);
    Ldeque(&q);
    Lenqueue(&q,122);
    display(&q);
    return 0;
}
