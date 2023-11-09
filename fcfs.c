
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>

#define QS 5

typedef struct Process{
  int id;
  int burst_time;
  char name[2];
  int arrival_time;
} prc;


void display(prc q[QS], int front, int rear);
void insert_front(prc q[QS], int *front, int *rear, prc item);
void insert_rear(prc q[QS], int *front, int *rear, prc item);
prc delete_front(prc q[QS], int *front, int *rear);
void delete_rear(prc q[QS], int *front, int *rear);

int main(void) {
    prc undone[QS];
    prc done[QS];

    int front = -1, rear = -1;
    int front_2 = -1, rear_2 = -1;
    prc p1,p2,p3,p4;

    p4.id=4;strcpy(p4.name,"P1");p4.burst_time=6;
  
    for (int i=4; i>0; i--) {
      //GET ID :wq
      scanf("%d %d %d",&p1.arrival_time,&p1.id,&p1.burst_time);
    }
  
    insert_rear(undone, &front, &rear, p1); 
    insert_rear(undone, &front, &rear, p2);
    insert_rear(undone, &front, &rear, p3); 
    insert_rear(undone, &front, &rear, p4);
    
    while (front!=rear+1) {
        //PROCESS IS DONE
        prc p = delete_front(undone, &front, &rear);
        printf("DOING PROCESS WITH PID=%d \n",p.id);
        sleep(p.burst_time);
  }
    
}
void insert_front(prc q[QS], int *front, int *rear, prc item) {
    if (*front == -1) {
        (*front)++;
        (*rear)++;
        q[*front] = item;
        return;
    }
    if (*front == 0) {
        printf("Cannot insert Process from the front\n");
        return;
    }
    q[--(*front)] = item;
}


void insert_rear(prc q[QS], int *front, int *rear, prc item) {
    if (*rear == -1) {
        (*rear)++;
        (*front)++;
        q[*rear] = item;
        return;
    } 
    if (*rear == QS - 1) {
        printf("Cannot insert item from rear.\n");
        return;
    }
    q[++(*rear)] = item;
}


prc delete_front(prc q[QS], int *front, int *rear) {
    if (*front < 0) {
        printf("No item to delete from front.\n");
        prc fail;
        strcpy(fail.name, "");
        fail.burst_time=0;
        fail.id=0;
        return fail;
    } 
    prc item = q[*front];
    (*front)++;
    return item;
}


