#include "solution.h"
#include <stdio.h>

int main(){
    int arr[] = {1,1,1};
    int size = sizeof(arr)/sizeof(int);

    removeDuplicates(arr, size);

    for(int i=0; i<size; i++){
        printf("%d ", arr[i]);
    }
    
    printf("\n");

    return 0;
}