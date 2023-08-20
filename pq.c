//Shittiest Implementation of PQ 
#include <stdlib.h>
#include <stdio.h>

enum Operation{
  Remove,
  Insert,
};


typedef struct
{
  int value;
  int priority;
} Element;

int ARR_SIZE = 1;
Element *arr;


void rem()
{
  int NEW_SIZE = ARR_SIZE - 1;
  arr = realloc(arr, NEW_SIZE * sizeof(Element));
  for (int i = 1; i < ARR_SIZE; ++i)
  {
    arr[i-1] = arr[i];
  }
  --ARR_SIZE;
  display(Remove);

}

void insert(int value, int priority)
{
  int NEW_SIZE = ARR_SIZE + 1;
  arr = realloc(arr, NEW_SIZE * sizeof(Element));
  ++ARR_SIZE;
  Element temp = {value, priority};
  for (int i = 0; i < ARR_SIZE; ++i)
  {

    if (priority < arr[i].priority)
    {
      continue;
    }
    else
    {
      for (int j = ARR_SIZE - 1; j >= i; j--)
      {
        arr[j] = arr[j - 1];
      }
      arr[i] = temp;
      break;
    }
  }
  display(Insert);
}

void display(enum Operation op)
{


    for (int i = 0; i < ARR_SIZE; ++i)
    {
      printf("%i : %i \n", arr[i].value, arr[i].priority);
    }
    switch (op)
    {
    case Insert:
      printf("Added Element \n");
      break;
    case Remove:
      printf("Renoved Top Element \n");
    }
  return;

}

int main()
{
  arr = calloc(1, sizeof(Element));
  if (arr == NULL)
  {
    printf("Fail LMAO");
    return 1;
  }

  arr[0].priority = 1;
  arr[0].value = 3;

  insert(2, 0);
  insert(3, 4);
  insert(21, 7);
  insert(90, 5);
  insert(5, 2);
  rem();
  insert(5, 3);

  

  free(arr);

  return 0;
}
