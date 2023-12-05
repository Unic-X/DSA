#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct node {
  char t;
  struct node* left;
  struct node* right;
}
node;


node * newNode(char val){
  node * n = malloc(sizeof(node));
  n->left = NULL;
  n->right = NULL;
  n->t = val;
  return n;
}


void inorder(node * n){
  if (n==NULL) {
   return; 
  }
  inorder(n->left);
  printf("%c",n->t);
  inorder(n->right);
}

node * toInfix(char * postfix){
  node * stack[100];
  int top = -1;

  node * x,*y,*operator;
  for (int i = 0; postfix[i] ; i++) {
    char curr = postfix[i];
    if (curr=='/' || curr =='*' || curr == '+' || curr=='-') {
      operator =  newNode(curr);
    operator->right =  stack[top--]; 
      operator->left = stack[top--]; 
      stack[++top] = operator;
    }else {
     stack[++top] = newNode(curr);
    }
    
  }

return stack[top--];

}

double eval(node * root){
  char symbol = root->t;
  switch (symbol) {
    case '+' : 
      return eval(root->left) + eval(root->right);
    case '-' : 
      return eval(root->left) - eval(root->right);
    case '*' : 
      return eval(root->left) * eval(root->right);
    case '/' : 
      return eval(root->left) / eval(root->right);
    default:
      return atoi(&symbol);
  }
}


int main(void) {
  char *string = "24+5*2+";
  node * tree = toInfix(string);
  printf("%f", eval(tree));
}


