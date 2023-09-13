#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
  int val;
  struct Node * next;
  struct Node * prev;
}node;

typedef struct DLinkedList{
  node head;
  node tail;
}DLL;

node * insertEnd(DLL* l,int val){  
  node * current = &(l->head);
  node *new = malloc(sizeof(node));
  while (current->next!=NULL) {
    current=current->next;
  }
  if (new != NULL)
  {
    new->val = val;
    current->next = new;
    new->next = NULL;
    new->prev = current;
  }
  return current->next;
}


void display(DLL *l)
{

  node *current = &(l->head);
  while (current != NULL)
  {
    printf("%i\n", current->val);
    current = current->next;
  }
  return;
}


int main(int argc, char *argv[])
{

  DLL list;
  insertEnd(&list,2);
  insertEnd(&list,3);
  insertEnd(&list,4);
  display(&list);

}
