#include <stdio.h> 
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

 // GOT THE QUESTION WRONG
// int* findLonely(int* nums, int numsSize, int* returnSize) {
//     int* lonely_arr =(int*)malloc(numsSize*sizeof(int));
//     int k=0; 
    
//     int hash[100000] = {0};
//     for(int i=0; i<numsSize; i++){
//         hash[nums[i]]++;
//     }
    
    
//     for(int i=0; i<numsSize; i++){
//         if(i==0){
//             if(nums[i+1] != nums[i] + 1 && nums[i+1] != nums[i] - 1 && hash[nums[i]]==1){
//                 lonely_arr[k] = nums[i];
//                 k++;
//             }
//             continue;
//         }

//         else if(i==numsSize-1){
//             if(nums[i-1] != nums[i] + 1 && nums[i-1] != nums[i] - 1 && hash[nums[i]]==1){
//                 lonely_arr[k] = nums[i];
//                 k++;
//             }
//             continue;
//         }

//         if(nums[i-1] != nums[i] + 1 && nums[i-1] != nums[i] - 1 &&
//             nums[i+1] != nums[i] + 1 && nums[i+1] != nums[i] - 1 && hash[nums[i]]==1){
//             lonely_arr[k] = nums[i];
//             k++;
//         }
//     }
    
//     *returnSize = k;
//     return lonely_arr;
// }   





// CORRECT SOLUTION.

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* findLonely(int* nums, int numsSize, int* returnSize){
    int min = nums[0], max = nums[0];
    for(int i = 1; i < numsSize; i++){
        if(nums[i] < min) min = nums[i];
        if(nums[i] > max) max = nums[i];
    }

    int offset = -min;  // Shift so that min+offset = 0
    int size = max - min + 3;  // Enough room for +/-1 neighbors
    int* hash =(int*)calloc(size, sizeof(int));
    int* lonely_arr =(int*)malloc(numsSize * sizeof(int));
    int k = 0;

    for(int i = 0; i < numsSize; i++){
        hash[nums[i] + offset]++;
    }

    for(int i = 0; i < numsSize; i++){
        int idx = nums[i] + offset;
        if(hash[idx]==1 && (idx==0 || hash[idx - 1]==0) && (idx + 1 >= size || hash[idx + 1]==0)){
            lonely_arr[k++] = nums[i];
        }
    }

    free(hash);
    *returnSize = k;
    return lonely_arr;
}
