int removeElement(int* nums, int numsSize, int val) {

    if(numsSize == 0){
        return 0;
    }

    //[0,1,2,2,3,0,4,2]     val = 2
    // 0 1 3 0 4 ----->ans

    int ans[numsSize];
    int k=0, count=0;
    for(int i=0; i<numsSize; i++){
        if(nums[i] != val){
            ans[k] = nums[i];
            k++;
        }
        else if(nums[i] == val){
            count++;
        }
    }
    
    for(int i=0; i<k; i++){
        nums[i] = ans[i];
    }

    return numsSize - count;
}