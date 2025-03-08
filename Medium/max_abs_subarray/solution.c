int maxAbsoluteSum(int* nums, int numsSize) {
  int result = 0;

  for (int i = 0; i < numsSize; i++) {
    int local_result = 0;

    for (int j = i; j < numsSize; j++) {
      local_result = nums[j] + local_result;

      if (local_result < 0) {
        if ((local_result * -1) > result) {
          result = local_result * -1;
        }
        continue;
      }

      if (local_result > result) {
        result = local_result;
      }
    }
  }

  return result;
}
