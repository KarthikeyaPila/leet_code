#include <limits.h>

// kadanes algo: 

int maxSubArray(int* arr, int arr_len) {
    int max = INT_MIN;
    int cur_sum = 0; 

    for(int i=0; i<arr_len; i++) {
        cur_sum += arr[i];

        if(max < cur_sum) {
            max = cur_sum; 
        }

        if(cur_sum <= 0) {
            cur_sum = 0; 
        }
    }

    return max;
}