#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode{
  int data ;
  struct TreeNode * l;
  struct TreeNode * r;
} node ;

node * treeInit(int val){
  node * new = malloc(sizeof(node));
  new->l = NULL;
  new->r = NULL;
  new->data = val;
  return new;

}



void insertNode(node * root,int val){
  node * new = malloc(sizeof(node));
  new->l = NULL;
  new->r = NULL;
  new->data = val;

  node * curr_prev = NULL;

  node * curr = root;
  
  while (curr!=NULL) {  
    curr_prev = curr;
    if (val < curr->data) {
      curr = curr->l;
    }else{
      curr = curr->r;
    }
  }
  if (val<curr_prev->data) {
    curr_prev->l = new;
  }else {
    curr_prev->r = new;
  }
}


void postorder(node * head){
  if (head==NULL) {
    return;
  };
  postorder(head->l);
  postorder(head->r);
  printf("%d",head->data);

}



void preorder(node * head){
  if (head==NULL) {
    return;
  };
 printf("%d",head->data);
  preorder(head->l);
  preorder(head->r);
}


void inorder(node * head){
  if (head==NULL) {
    return;
  };
  inorder(head->l);
  printf("%d \n",head->data);
  inorder(head->r);
 
}




void inorderIter(node * head){
  node * curr = head;
  node * stack[100];
  int top = -1;
  while (1) {
  
    while (curr!=NULL) {
      stack[++top] = curr;
      curr = curr->l;
    }

    if (top!=-1) {
      curr = stack[top--];
      printf("%d",curr->data);
      curr = curr->r;
    }
    else {
      return;
    }
  }
}



void deleteNode(node * root,int val){
  node * curr = root;
  node * parent = root;
  while (curr!=NULL && curr->data != val) {
    parent = curr;
    if (curr->data > val) {
      curr = curr->l;
    }else{
      curr = curr->r;
    }
  }

  if (curr->l ==NULL && curr->r == NULL) {
    if (parent->data < val) {
      parent->r = NULL;
    }
    else {
    parent->l = NULL;
    }
  }else if (curr->l == NULL) {
    if ( val < parent->data) {
      parent->l = curr->r;
    }else{
      parent->r = curr->r;
    } 
  }else if (curr->r == NULL) {
    if (val < parent->data) {
      parent->l = curr->l;
    }
    else {
    parent->r = curr->l;
    }
  }else {
    if (val < parent->data) {
      parent->l = curr->r;
      parent = parent->l;
    }else {
      parent->r = curr->r;
      parent = parent->r;
    }
    while (parent->l!=NULL) {
      parent = parent->l;
    }
    parent->l = curr->l;

 }
  free(curr);
}

int inorderSucc(node * root,int val){
 
  node * traveller = root;
  node * succ = NULL;
  
  while (traveller!=NULL) {
    if (traveller->data <=val) {
      traveller = traveller->r;
    }else {
      succ = traveller;
      traveller = traveller->l;
    }
  
  }
  if (succ==NULL) {
    return -1;
  }
  return succ->data;
}
int main(int argc, char *argv[])
{
  node * t = treeInit(8);
  insertNode(t, 5);
  insertNode(t, 1);
  insertNode(t, 9);
  insertNode(t, 8);
  deleteNode(t, 9);
  printf("%d",inorderSucc(t, 8));
  

}
