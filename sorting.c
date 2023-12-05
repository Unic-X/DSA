#include <stdio.h>

void insertion(int * arr,int n){
  for (int i=1; i<n; i++) {
    int j = i-1;
    int key = arr[i];
    while (j>=0 && arr[j]>key) {
      arr[j+1] = arr[j];
      j--;
    }
    arr[j+1] = key;
  }
}



void selection(int * arr,int n){
  for (int i=0; i<n-1; i++) {
    int min_idx = i;
    for (int j = i+1; j < n; j++) 
      if (arr[min_idx]> arr[j]) 
        min_idx = j;
    
    if (min_idx!=i) {
      int temp = arr[i];
      arr[i] = arr[min_idx];
      arr[min_idx] = temp;
    }
  }
}


void bubble(int * arr,int n){
  for (int i=0; i<n-1; i++) {
    for (int j=0; j < n-i-1; j++) {
      if (arr[i] > arr[j]) {
         int temp = arr[i];
         arr[i] = arr[j];
         arr[j] = temp;
      }
    }
  }
}


int main(int argc, char *argv[])
{
  int arr[] = {2,46,3,35,74,12};
  bubble(arr, 6);

  for (int i=0; i<6; i++) {
    printf("%d\n",arr[i]);
  }
}
