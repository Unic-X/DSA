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
    q->head = -1;
    q->size = max_size;
    q->tail = -1;
    q->values = malloc(sizeof(int)*max_size);
    return q;
}

bool isQEmpty(queue * q){
    return (q->head==-1 && q->tail==-1);
}

bool isQFull(queue * q){
    return((q->tail+1)%q->size==q->head);
}

void enqueue(queue * q,int value){
    if (isQFull(q))
    {
        printf("Cannot Insert Element QUEUE is FULL!!  \n");
        return;
    }

    
    if (q->head==-1 && q->tail==-1)
    {
        q->head=0;
    }

    q->tail = (q->tail+1) % q->size;
    q->values[q->tail] = value;

    
}


void dequeue(queue * q){
    if (isQEmpty(q))
    {
        printf("Cannot Delet Element QUEUE is EMPTY!!  \n");
        return;
    }

    if (q->head==q->tail)
    {
        q->head=-1;
        q->tail=-1;

    }
    
    q->head = (q->head+1) % q->size;
    
}


void display(queue * q){
    int curr = q->head;
    printf("\n");
    printf("Value: %d \n",q->values[curr]);
    
    if (q->tail == -1) {
      printf("EMPTY LIST \n");
      return;
    }

    while (curr!=q->tail)
    {
        curr = (curr+1) % q->size;
        printf("Value: %d \n",q->values[curr]);
    }
}

int main()
{
    queue q;

    queueInit(&q,5);

    enqueue(&q,5);
    enqueue(&q,9);
    enqueue(&q,7);
    enqueue(&q,0);
    enqueue(&q,1);
    
    display(&q); // FULL 5->9->7->0->1

    enqueue(&q,1); //FULL CANNOT INSRRT

    dequeue(&q);
    dequeue(&q);
    
    enqueue(&q, 99);

    display(&q); // 7->0->1->99

    enqueue(&q,8);

    enqueue(&q,99999);
    enqueue(&q,1111111);

    display(&q); //FULL x2


    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);

     display(&q);

}
