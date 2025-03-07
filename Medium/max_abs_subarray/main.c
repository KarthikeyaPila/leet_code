#include <assert.h>
#include "solution.h"

int main() {
  int nums0[] = {1,-3,2,3,-4};
  int nums1[] = {2,-5,1,-4,3,-2};

  int result0 = maxAbsoluteSum(nums0, sizeof(nums0)/sizeof(nums0[0]));
  int result1 = maxAbsoluteSum(nums1, sizeof(nums1)/sizeof(nums1[0]));

  assert(result0 == 5);
  assert(result1 == 8);
}
