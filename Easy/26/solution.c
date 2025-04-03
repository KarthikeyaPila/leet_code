int removeDuplicates(int* nums, int size) {
    if(size == 0){
        return 0;
    }
    int count=0;

    for(int i=0; i<size; i++){
        for(int j=i+1; j<size; j++){
            if(nums[j] == nums[i] && nums[j] != INT_MAX){
                nums[j] = INT_MAX;
                count++;
            }
        }
    }

    for(int i=0; i<size-1; i++){
        for(int j=0; j<size-i-1; j++){
            if(nums[j+1] < nums[j] || nums[j] == INT_MAX && nums[j+1] != INT_MAX){
                int temp = nums[j+1];
                nums[j+1] = nums[j];
                nums[j] = temp;
            }
        }
    }

    return size - count;
}