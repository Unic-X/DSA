#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *insertF(node *a, int val)
{
    struct node *temp;
    temp = (node *)malloc(sizeof(*temp));
    if (temp == NULL)
    {
        printf("Cannot allocate mem");
        exit(-1);
    }
    if (a == NULL)
    {
        temp->data = val;
        temp->next = NULL;
        a = temp;
        return a;
    }

    temp->data = val;
    temp->next = a;
    return temp;
}

node *insert(node *a, int val)
{
    struct node *temp;
    temp = (node *)malloc(sizeof(*temp));
    if (temp == NULL)
    {
        printf("Cannot allocate mem");
        exit(-1);
    }
    if (a == NULL)
    {
        temp->data = val;
        temp->next = NULL;
        a = temp;
        return a;
    }

    node *curr = a->next;

    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    temp->data = val;
    curr->next = temp;

    temp->next = NULL;

    return a;
}

void display(node *list)
{
    if (list == NULL)
    {
        printf("GAlat");
        return;
    }

    node *curr = list;
    while (curr != NULL)
    {
        printf("%d \n", curr->data);
        curr = curr->next;
    }
}

void freeList(node * head) {
    node* current = head;
    node* nextNode;

    while (current != NULL) {
        nextNode = current->next;
        free(current); // Free the current node
        current = nextNode;
    }

    // Set the head pointer to NULL to indicate an empty list
    head = NULL;
}


int flyod(node * head){
    node * fP = head;
    node * sP = head;

    while (1)
    {
        fP = fP->next;
        if (fP==NULL)
        {
            return 0;
        }
        if (fP==sP)
        {
            return 1;
        }
        fP= fP->next;
        if (fP==NULL)
        {
            return 0;
        }
        if (fP==sP)
        {
            return 1;
        }
        sP=sP->next;

    }
    
    

}


int main()
{
   node n1,n2,n3,n4,n5;

   n1.data=1;
   n2.data=2;
   n3.data=3;
   n4.data=4;
   n5.data=5;

   n1.next=&n2;
   n2.next=&n3;
   n3.next=&n4;
   n4.next=&n5;
   n5.next=&n3;
   
    if (flyod(&n1))
    {
        printf("Has Cycle \n");
    }else{
        printf("No Cycle \n");
    }
    

    

}
