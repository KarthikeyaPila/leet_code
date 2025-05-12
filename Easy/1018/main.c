#include <stdio.h> 
#include <stdbool.h>
#include <math.h>
#include <stdlib.h> 

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int bin_to_decimal(int* arr, int arr_len){
    int result = 0; 
    for(int i=arr_len-1; i>=0; i--){
        if(arr[i] == 1){
            result += pow(2, arr_len-1-i);
        }
    }

    return result;
}

bool* prefixesDivBy5(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    bool *bool_arr = malloc(*returnSize*sizeof(bool));

    for(int i=0; i<numsSize; i++){
        int decimal_val = bin_to_decimal(nums, i+1);
        bool_arr[i] = (decimal_val%5 == 0);
    }

    return bool_arr;
}

int main(){
    int arr[] = {0,1,1};
    int numsSize = sizeof(arr)/sizeof(arr[0]);
    int returnSize;

    bool* bool_arr = prefixesDivBy5(arr, numsSize, &returnSize);

    for(int i=0; i<numsSize; i++){
        printf("%d ", bool_arr[i]);
    }

    printf("\n");

    free(bool_arr);
    return 0;
}