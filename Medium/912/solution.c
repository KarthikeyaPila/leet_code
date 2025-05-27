/**
 * Note: The returned array must be malloced, assume caller calls free().
 */


// Impliemented merge sort.
void merge(int* arr, int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int leftArr[n1], rightArr[n2];

    for (i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        }
        else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}
void mergeSort(int* arr, int left, int right) {
    if (left < right) {
      
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}
int* sortArray(int* nums, int numsSize, int* returnSize) {
    mergeSort(nums,0,numsSize-1);
    *returnSize = numsSize;
    return nums;
}
    

// i can also use a hashmap as the size of the data is really less.
// #include <stdlib.h>

// int* sortArray(int* nums, int numsSize, int* returnSize) {
//     int offset = 50000;
//     int freq[100001] = {0};

//     for (int i = 0; i < numsSize; i++) {
//         freq[nums[i] + offset]++;
//     }

//     int* result = (int*)malloc(numsSize * sizeof(int));
//     int index = 0;

//     for (int i = 0; i < 100001; i++) {
//         while (freq[i]-- > 0) {
//             result[index++] = i - offset;
//         }
//     }

//     *returnSize = numsSize;
//     return result;
// }
