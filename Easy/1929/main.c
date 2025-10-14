/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getConcatenation(int* nums, int numsSize, int* returnSize) {
    *returnSize = 2*numsSize;
    
    int *ret_arr = (int*)malloc(*returnSize*sizeof(int));

    int i=0; 
    for(; i<numsSize; i++){
        ret_arr[i] = nums[i];
    }
    for(int j=0; j<numsSize; j++){
        ret_arr[i++] = nums[j];
    }

    return ret_arr;
}