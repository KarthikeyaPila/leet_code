#include <stdio.h> 

// low, mid, high => 0 1 2
// if num[mid] == 0 -> swap with low, increase both mid and low pointer.
// if num[mid] == 1 -> just move mid
// if num[mid] == 2 -> swap with high and decrease high and DO NOT INCRIMENT MID. 

void sortColors(int* nums, int numsSize) {
    int low = 0;
    int mid = 0;
    int high = numsSize - 1;

    while (mid <= high) {
        if (nums[mid] == 0) {
            // Swap nums[low] and nums[mid]
            int temp = nums[low];
            nums[low] = nums[mid];
            nums[mid] = temp;
            low++;
            mid++;
        } else if (nums[mid] == 1) {
            mid++;
        } else {
            // nums[mid] == 2
            int temp = nums[mid];
            nums[mid] = nums[high];
            nums[high] = temp;
            high--;
        }
    }

    for(int i=0; i<numsSize; i++){
        printf("%d ", nums[i]);
    }

    printf("\n");

    return;
}
