/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int hash[20001] = {0};
int MOD = 10000;  

int cmp(const void *a, const void *b) {
    int *x = (int*)a;  
    int *y = (int*)b; 
    return hash[*y + MOD] - hash[*x + MOD];  
}

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
    for (int i = 0; i < 20001; i++) {
        hash[i] = 0; 
    }
    for (int i = 0; i < numsSize; i++) {
        hash[nums[i] + MOD]++; 
    }
    *returnSize = k ;
    int *res = (int *)malloc(k * sizeof(int)); 
    qsort(nums, numsSize, sizeof(int), cmp); 
    int cnt = 0; 
    int i = 0; 
    while(cnt < k && i < numsSize) {
        if (hash[nums[i] + MOD]) {
            res[cnt] = nums[i]; 
            ++cnt; 
            hash[nums[i] + MOD] = 0;  
        }
        ++i; 
    }
    return res; 
}