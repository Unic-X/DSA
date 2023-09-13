#include <stdio.h>
#include <stdlib.h>

enum Bool
{
  False,
  True,
};

typedef struct Node
{
  int val;
  struct Node *next;
} node;


node *push(node *p, node *n)
{
  node current = *p;
  node *new = malloc(sizeof(node));
  if (new != NULL)
  {
    new->val = n->val;
    (*p).next = new;
    new->next = NULL;
  }
  return current.next;
}

void display(node *start)
{

  node *current = start;
  while (current != NULL)
  {
    printf("%i\n", current->val);
    current = current->next;
  }
  return;
}

void pop(node *p)
{
  node *current = p;
  while (True)
  {
    if (current->next->next == NULL)
    {
      current->next = NULL;
      break;
    }
    else
    {
      current = current->next;
    }
  }
}

int main()
{

  node *one = malloc(sizeof(node));
  node *two = malloc(sizeof(node));
  node *three = malloc(sizeof(node));

  one->val = 2;
  one->next = two;

  two->val = 4;
  two->next = NULL;

  three->val = 6;
  three->next = NULL;

  push(two, three);
  pop(one);

  display(one);
  return 0;
}
