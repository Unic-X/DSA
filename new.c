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



int main()
{
    node *list = NULL;

    for (int i = 0; i < 20000; i++)
    {
        list = insertF(list, i);
    }


    display(list);

    freeList(list);
}
