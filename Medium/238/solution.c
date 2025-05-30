#include <stdio.h> 
#include <stdlib.h>
#include <string.h> 

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

 // O(n) approach. TWO PASS APPROACH
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int *out = malloc(sizeof(int)**returnSize);
    memset(out, 1, sizeof(int)*numsSize);
    
    out[0] = 1;
    // left to right.
    for(int i=1; i<numsSize; i++){
        out[i] = out[i-1]*nums[i-1];
    }

    // right to left.
    int r = 1;
    for(int i=numsSize-1; i>=0; i--){
        out[i] *= r;
        r *= nums[i];
    }

    return out;
}

int main(){
    int num[4] = {1,2,3,4};
    int returnsize;
    int *arr = productExceptSelf(num, 4, &returnsize);

    for(int i=0; i< returnsize; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
