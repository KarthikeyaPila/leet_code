
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int* ret = malloc(sizeof(int) * 2);
    int* end = nums + numsSize;
    int* pi, *pj;
    int target_j;
    for (pi = nums; pi != end; pi++) {
        target_j = target - *pi;
        for (pj = pi + 1; pj != end; pj++) {
            if (target_j == *pj){
                ret[0] = pi - nums;
                ret[1] = pj - nums;
                *returnSize = 2;
                return ret;
            }
        }
    }
    return ret;
}