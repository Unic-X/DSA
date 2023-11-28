#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define increase(arr) ((int*)realloc(arr,(size*2)*sizeof(int)));


int size=0;


int * insert(int * arr,int val){
    if(size==0){
        size++;
        arr[0] = val;
        return arr;
    }
    if(size== ((int)sizeof(arr)/sizeof(int))) arr = increase(arr);
     
    arr[size] = val;
    size++;
    return arr;
}

void display(int * arr){
    for(int i=0;i<size;i++){
        printf("D[%d] I[%d] \n",arr[i],i);
    }
    
}

int * del(int * arr){
    if(size==0){
        printf("Size is 0 cannot delete elements");
        exit(-1);
    }
    int * new;
    new = (int*)malloc((size-1)*sizeof(int));
    size--;
    int i = 1;
    while (i<=size)
    {
        new[i-1] = arr[i];
        i++;
    }
    return new;
    
                }

int main()
{   
    int* ptr;
    ptr = (int*)malloc(size * sizeof(int));
    if (ptr==NULL)
    {
        printf("Cannot Allot mem");
        exit(-1);
    }


    clock_t t;
    t = clock();

    
    for (int i = 0; i < 200000000; i++)
    {
        ptr = insert(ptr,i);
    }
    
    
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds

    printf("took %f seconds to execute \n", time_taken);




    free(ptr);

}
