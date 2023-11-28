#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
  int val;
  struct Node * next;
  struct Node * prev;
}node;

typedef struct DLinkedList{
  node * head;
  node * tail;
}DLL;

b
/*DLL createDLL(int val){
  DLL list;
  node n;
  n.val=val;
  list.head=n;
  list.tail=n;
  return list; 
}*/

node * deleteFront(node * list){
  node * new_head = list->next;
  node * last_node=list->prev;
  free(list);
  list = new_head;
  list->prev=last_node;
  last_node->next=list;
  return new_head;
}

void deleteLast(node * list){
 node * current = list;
  while (current->next!=list) {
    current=current->next;
  }
  node * last_node = current->prev;
  free(current);
  list->prev=last_node;
  last_node->next=list;

}

node * insertFront(node * list,int val){
  node * current = list;
  node * new = (node *)malloc(sizeof(node));
  new->val=val;
 new->next=list;
  list->prev=new;


  while(current->next!=list){
    current= current->next;
  }
  current->next = new;
   new->prev=current;
  list=new;
  return list;
}
node * insertEnd(node * list,int val){ 
  node * current = list;
  node *new = (node *)malloc(sizeof(node));
  while (current->next!=list) {
    current=current->next;
  }
  if (new != NULL)
  {
    new->val = val;
    current->next = new;
    list->prev=new;
    new->next = list;
    new->prev = current;
  }
  return list;
}


void display(node * list)
{

  node *current = list->next;
  while (current != list)
  {
    printf("%i \n", current->val);
    current = current->next;
  }
}

void destroy(node * list) {
  node *current = list;
  while(current != list) {
    node *temp = current;
    current = current->next;
    free(temp);
  }
}

node * create_list(int val){
  node * list = (node *)malloc(sizeof(node)); 
  list->next=list;
  list->prev=list;
  list->val=val;
  return list;
}
int main()
{
  node * list = create_list(1);
  list = insertEnd(list,2);
  list = insertEnd(list,3);
  list = insertEnd(list,4);
  list = insertFront(list,5);
  list = insertFront(list,7);
  list = insertFront(list,9);
  display(list);printf("\n\n");
  list = deleteFront(list);
  display(list);printf("\n\n");
  deleteLast(list);
  display(list);
  destroy(list);

}
