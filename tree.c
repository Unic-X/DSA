#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <sys/types.h>


typedef struct Node{
  int64_t data;
  struct Node * left;
  struct Node * right;
}node ;

node *create(int64_t data) {
  node *new = malloc(sizeof(node));
  new->data = data;
  new->left = NULL;
  new->right = NULL;
  return new;
}
 

node * add_node(node * parent,int64_t data){
  if (parent->left==NULL || parent->right==NULL) {   
    node * _child = (node*)malloc(sizeof(node));

    _child->data=4;_child->left=NULL;_child->right=NULL;
  
    if (parent->left == NULL) {
      parent->left =_child;  
    }else{
      parent->right =_child;
    } 
  return _child;

  }else {
    return NULL;
  }
}


void trav_I(node * root){
  node * stack[200];
  u_int pos = -1;
  node * curr = root;
  for(;;){
    while (root!=NULL) {
      printf("%" PRIu64 "\n",curr->data);
      stack[++pos] = curr;
      curr=curr->left;
    }
    if (pos!=-1) {
      

    }

  }

}



int main()
{
  node * root = create(10);
  node * b = add_node(root, 5);
  node * c = add_node(root, 7);
  node * d = add_node(c , 9); 
  trav_I(root);

  free(d);
  free(c);
  free(b);
  free(root);
}
