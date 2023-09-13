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
  Element* left ;
  Element* right;
} Element;

Element* arr;
