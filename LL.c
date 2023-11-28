#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>

typedef struct LinkedList
{
    int data;
    struct LinkedList * next;
}node;

 node * initLL(){
  node * head = malloc(sizeof(node));
  head->next = NULL;
  return head;
}

void addEndItem(node * ll,int val){
    node * curr = ll;
    node * new = malloc(sizeof(node));
    while (curr->next!=NULL) {
      curr=curr->next; 
    }
    
    new->data = val;
    new->next = NULL;
    curr->next = new;

    return;
    
    
}

void addFrontItem(node * ll,int val){
  if (ll==NULL)
    {
      ll->data = val;
      ll->next = NULL;
      return;
    }

  node * new = malloc(sizeof(node));
  
  new->next = ll->next;
  new->data = val;
  ll->next = new;
  return;
}

void display(node* ll){
  node * curr = ll->next;
  while (curr!=NULL) {
    printf(" %d->",curr->data);
    curr = curr->next;
  }
  printf("\n");
}


node * deleteFront(node * ll){
  
  node * n = ll->next;
  
  if (n==NULL) {
    printf("No item in list to delet\n ");
    return NULL;
  }
  
  ll->next = n->next;
 
  return n;

}

void deleteRear(node * ll){
  
  node * curr = ll;

  if (curr->next==NULL) {
    return ;
  }

  while (curr->next->next!=NULL) {
    curr= curr->next;
  }
  
  node * prev = curr;

  curr->next=NULL;

}

void insertFront(node * head, int val){
  node * temp = malloc(sizeof(node));
  temp->data = val;
  temp->next = NULL;
  temp->next = head->next;
  head->next = temp;

}

void insertatN(node * head,int val,int pos){
  node * temp = malloc(sizeof(node));

  node * curr = head;
  temp->data = val;
  for (int ind = -1 ; ind < pos -1 ; ind++ ) {
    if (curr==NULL) {
      printf("Invalid Position trying to write in overflow\n");
      return;
    }
    curr = curr->next;
  }
  temp->next = curr->next;
  curr->next = temp;
}


node * orderLL(int values[],int size){
  node * head = initLL();
  head->next = NULL;
  head->data = 0;
  for (int ind = 0; ind<size; ind++) {
    node * new = malloc(sizeof(node));
    new->next = NULL;
    new->data = values[ind];
    if (!(head->next)) {  
      head->next = new;
      continue;
    }
    node * curr = head;
    while (curr->data > curr->next->data) {
      curr= curr->next;
    }
    curr->next = new;
  } 

  return head;
}

int main()
{
    node * head = initLL();
    addEndItem(head,5);
    addEndItem(head, 2);
    addEndItem(head, 8);
    addEndItem(head, 0);
    addFrontItem(head, 9);

    deleteFront(head);

    deleteRear(head);


  
    int vals[7] = {1,2,3,4,5,3,2}; 
    node * real = orderLL(vals,7);
    display(real);
    return 0;
}


