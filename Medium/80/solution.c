#include <string.h>

int removeDuplicates(int* nums, int size) {
    int j = 0;
    int count=1;
    int dup_rem_count = 0;
    int arr[size];
    
    int focus_var = arr[0];

    for(int i=0; i<size; i++){
        if(nums[i] == focus_var && count < 2){
            arr[j] = nums[i];
            j++;
            count++;
        }
        else if(nums[i] != focus_var){
            focus_var = nums[i];
            count = 1;
            arr[j] = focus_var;
            j++;
        }
        else if(nums[i] == focus_var && count > 1){
            dup_rem_count++;
        }
    }

    memcpy(nums, arr, sizeof(int)*size);

    return size-dup_rem_count;
}