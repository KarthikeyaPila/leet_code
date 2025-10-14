int subarraySum(int* nums, int numsSize, int k){
    int hash[20000000] = {0};
    int sum = 0,count = 0;
    
    hash[10000000] = 1;
    for(int i = 0;i<numsSize;i++){
        sum += nums[i];
        count += hash[sum-k+10000000];
        hash[sum+10000000]++;
    }

    return count;
}