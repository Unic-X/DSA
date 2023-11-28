#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node* next;
} node;

void insertFront(node * head,int val){
  node * new = malloc(sizeof(node));
  new->data = val;
 
  if (head->next==head) {
    head->next = new;
     new->next = new;
    return;
  }
  node * curr = head->next;
  while (curr->next!=head->next) {
    curr = curr->next;
  }
  curr->next = new;
  new->next = head->next;

}

void insertBack(node * head,int val){
  node * new = malloc(sizeof(node));
  new->data = val;
   if (head->next==head) {
    head->next = new;
    new->next = new;
 
    return;
  }
  node * curr = head->next;
  while (curr->next!=head->next) {
    curr = curr->next;
  }
  curr->next = new;
  new->next = head->next;
  head->next = new;

}

void deleteBack(node * head){
  if (head->next == NULL) {
    printf("NO ELEMENT TO DELET\n");
    return;
  }

  node * curr = head->next;
  node * to_del = head->next;
  

  head->next = head->next->next;
    while (curr->next!=to_del) {
    curr= curr->next;
  }

  curr->next = head->next;
  free(to_del);
  
}

void display(node* ll){
  node * curr = ll->next;
  do {
    printf("%d->",curr->data);
    curr = curr->next;
  }
  while (curr != ll->next);
  printf("....\n");
}

node * cllInit(){
  node * new = malloc(sizeof(node));
  new->next = new;
  new->data = 0;
  return new;
}
int main(int argc, char *argv[])
{
  node * cll = cllInit();
  insertFront(cll, 6);
  insertFront(cll, 7);
  insertBack(cll, 2);
  insertBack(cll, 90);
  deleteBack(cll);
  display(cll);
}
