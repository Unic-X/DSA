#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

uint64_t max(uint64_t l,uint64_t r){
  return l > r ? l : r;
}

typedef struct Node{
  uint64_t val;
  struct Node * l;
  struct Node * r;
}node;


typedef struct tree
{
  node * root;
}tree;


typedef struct node_m{
  node * parent;
  node * to_del;
}s ;

node * make_node(uint64_t val){
  node * _temp = (node *)malloc(sizeof(node));
  _temp->r = NULL;
  _temp->l = NULL;
  _temp->val = val;
  return _temp;
}

void BST_INSERT(tree * T, uint64_t z){
    node * y = (node *)malloc(sizeof(node));    // CREATE A NODE Y THAT
    node * curr =  T->root;     // SET CURRENT NODE TO ROOT
    node * new = make_node(z);  // CREATE NEW NODE
    while (curr!=NULL) {
        y = curr;              
        if (z<curr->val) {
            curr = curr->l;
        }else{
            curr = curr->r;
        }
    }
  if (z<y->val) {
    y->l = new;
  }else{
    y->r = new;
  }
}
void postorder(node * n){
  if (n==NULL) {
   return; 
  }
  postorder(n->l);
  postorder(n->r);
  printf("%ld \n",(long)n->val);
 
}


void preorder(node * n){
  if (n==NULL) {
    return;
  
  }
  printf("%ld  -> ",(long)n->val);
  preorder(n->l);
  preorder(n->r);
}
s * search(tree * t,uint64_t n){
  node * curr = t->root;
  node * parent = t->root; 
  while (curr!=NULL && n!=curr->val) {
    parent = curr;
  
    if (n < curr->val) {
      curr = curr->l;

    }else{
      curr = curr->r;

    }
  }
  s * node_m = (s *)malloc(sizeof(s));
  node_m->parent = parent;
  node_m->to_del = curr;
  return node_m; 
}

void inorder(node * n){
  if (n==NULL) {
   return; 
  }
  inorder(n->l);
  printf("%ld \n",(long)n->val);
  inorder(n->r);
}

uint64_t height(node * n){
  if (n==NULL) {
    return -1;
  }
  return max(height(n->l), height(n->r))+1; 

}


void delete_node(tree * t, uint64_t n){
  s * to_del = search(t, n); 
  node * parent = to_del->parent;

  node * todel = to_del->to_del;
  

  if (todel == NULL) {
    printf("Cannot Find the Node n");
    return;
  }  
  if (todel->r == NULL && todel->l==NULL) {
      if (parent->val < n) {
        parent->r=NULL;
      }else{
        parent->l=NULL;
    }
  }else if (todel->r == NULL) {
    if (n < parent->val) {
      parent->l=todel->l;
    }else {
      parent->r = todel->l;
    }
  }else if (todel->l == NULL) {
    if (n < parent->val) {
      parent->l=todel->r;
    }else {
      parent->r = todel->r;
    }
  }else {
    if (n<parent->val) {
      parent->l = todel->r;
      parent = parent->l;
    }
    else{
      parent->r = todel->r;
      parent = parent->r;
    }
    while (parent->l!=NULL) {
      parent = parent->l;
    }
    parent->l = todel->l;
  }
  free(todel);
}
void inordersucc(tree* t, uint64_t n){
    s * temp = search(t,n);
    node * cur = temp->to_del;
    node * del = temp->parent; 
    cur=cur->r;
    while(cur->l!=NULL){
      cur=cur->l;
    }
    cur->l = del->l;
}
void inorder_pred(node * root){
  if (root==NULL) {
    return;
  }
  node * tree[100];
  node * current = root;

  int top = -1;

  while (1) {
    while (current!=NULL) {
      tree[++top] = current;
      current = current->l;
    }

    if (top!=-1) {
      current = tree[top--];
      printf("%d",(int)current->val);
      current= current->r;
    }
    else {
    return;
    }
  }
  return; 

}

void stack_post(node * root){
  node * stack[100], * stackp[100];
  int top=-1;
  int topP = -1;

  node * curr = root;
  stack[++top] = curr;
  while (top!=-1) {
    stackp[++topP] = stack[top--];
    curr = stackp[topP];
    if (curr->l!=NULL) {
      stack[++top] = curr->l;
    }
    if(curr->r!=NULL){
      stack[++top] = curr->r;
    }
  }
  while (topP!=-1) {
    printf("%d ->" , (int)stackp[topP--]->val);
  }

}


int main()
{
  tree * t = (tree *)malloc(sizeof(tree));

  t->root = make_node(5); 
  BST_INSERT(t, 8);
  BST_INSERT(t, 1);
  BST_INSERT(t, 10);
  BST_INSERT(t, 33);
  BST_INSERT(t, 2);
  BST_INSERT(t, 0);
  BST_INSERT(t, 7);
  printf("PREORDER: \n");preorder(t->root);printf("\n");

  printf("INORDER: \n");inorder(t->root);printf("\n");

  printf("POSTORDER: \n");stack_post(t->root);printf("\n");


  inorder(t->root);
  inorder_pred(t->root);
  printf("\n\n");
  printf("%d" , (int)height(t->root));
}
