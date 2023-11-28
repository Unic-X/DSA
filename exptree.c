#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef char token[20];
typedef struct node {
  token t;
  struct node* left;
  struct node* right;
}
node;



token* tokenize(char* string);

int main(void) {
  char *string = "23,4+56*";
}


token* tokenize(char* string){
  token loda = (token *)malloc(sizeof(token));
  for (int i=0; i<strlen(const char *); i++) {
    if (string[i]==',') {
      continue;
    } 
  }
}
