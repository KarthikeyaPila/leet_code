int removeDuplicates(int* nums, int numsSize) {
    int i = 0;
    for(int j = 1; j<numsSize; j++){
        if(nums[j]!= nums[i]){
            i++;
            nums[i] = nums[j];
        }
    }
    int k = i+1;
    return k;
}