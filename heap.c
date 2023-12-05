#include <stdio.h>
#include <stdlib.h>

void BT_heapify(int arr[], int n);
void BT_heap_sort(int arr[], int n);
void print_arr(int arr[], int n);
void TD_heapify(int arr[], int n);

int main(void) {
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120};
    TD_heapify(arr, 12);  
  print_arr(arr, 12);
}

void print_arr(int arr[], int n) {
    for (int i = 0; i < n; i++) {
	printf("%d ", arr[i]);
    }
    printf("\n");
}

void BT_heapify(int arr[], int n) {
  for (int i = n / 2 - 1; i >= 0; i--) {
	int parent = i;
	int item = arr[parent];
	int child = 2 * parent + 1;
	while (child <= n - 1) {
	    if ((child + 1 <= n - 1) && arr[child] < arr[child + 1]) {
		child++;
	    }
	    if (item < arr[child]) {
		arr[parent] = arr[child];
		parent = child;
		child = 2 * parent + 1;
	    } else {
		break;
	    }
	}
	arr[parent] = item;
    }
}

void BT_heap_sort(int arr[], int n) {
    BT_heapify(arr, n);
    print_arr(arr, n);
    for (int i = n - 1; i >= 0; i--) {
	int temp = arr[i];
	arr[i] = arr[0];
	arr[0] = temp;
	print_arr(arr, n);
	BT_heapify(arr, i);
	print_arr(arr, n);
    }
}

void TD_heapify(int arr[], int n) {
    for (int i = 1; i < n; i++) {
	int child = i;
	int key = arr[child];
	int parent = child / 2 - 1;
	while (child > 0) {
	    if (key > arr[parent]) {
		arr[parent] = key;
		child = parent;
		parent = child / 2 - 1;
	    } else {
		break;
	    }
	}
	arr[parent] = key;
    }
}


void TD_heap_sort(int arr[], int n) {
    TD_heapify(arr, n);
    print_arr(arr, n);
    for (int i = n - 1; i >= 0; i--) {
	int temp = arr[i];
	arr[i] = arr[0];
	arr[0] = temp;
	print_arr(arr, n);
	TD_heapify(arr, i);
	print_arr(arr, n);
    }
}
