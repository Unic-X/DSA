#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct Heap{
  int * data;
  size_t size;
} heap ;


void heapify(heap * h){
  for (int i = (h->size / 2)-1; i>=0 ; i--){ 
    int parent = i;
    int item = h->data[parent];
    int child = 2 * parent + 1;

    while (child<=h->size-1) {
      if ((child + 1 <= h->size-1)  && (h->data[child] < h->data[child+1])) {
        child++;
      }
      if (item < h->data[child]) {
        h->data[parent] = h->data[child];
        parent = child;
        child = 2 * parent + 1;

      }else {
        break;
      }
    }
    h->data[parent] = item;
  }
}


void heapifyTD(heap * h){
  for (int i = 1; i<h->size ; i++){ 
    int child = i;
    int item = h->data[child];
    int parent = child/2-1;

    while (child>0) {
      if (item > h->data[parent]) {
        h->data[parent] = item;
        child = parent;
        parent = child / 2  - 1;

      }else {
        break;
      }
    }
    h->data[parent] = item;
  }
}



heap* arr_init(int max_size){
  heap * h = malloc(sizeof(heap));
  h->size = max_size;
  h->data = malloc(sizeof(int)*max_size);
  return h;
}

void BT_heap_sort(heap * h){
  int orig_size = h->size;
  heapify(h);
  for (int i = h->size-1; i>=0; i--) {
    h->data[i] ^= h->data[0];
    h->data[i] ^= h->data[0];
    h->data[i] ^= h->data[0];
    h->size=i;
    heapify(h);
  }
  h->size = orig_size;
}


int main()
{
  heap * test = arr_init(10);
  for (int i=0; i<10; i++) {
    test->data[i] = i;
  }
  heapifyTD(test);
 for (int i=0; i<test->size; i++) {
    printf("%d ",test->data[i]);
  }

  
}
